------------------------------------------------------------------------------
--                                                                          --
--                 GNU ADA RUNTIME LIBRARY (GNARL) COMPONENTS               --
--                                                                          --
--     S Y S T E M . T A S K _ P R I M I T I V E S . O P E R A T I O N S    --
--                                                                          --
--                                  B o d y                                 --
--                         (Version for new GNARL)                          --
--                                                                          --
--                             $Revision: 1.1 $                            --
--                                                                          --
--   Copyright (C) 1991,1992,1993,1994,1995,1996 Florida State University   --
--                                                                          --
-- GNARL is free software; you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion. GNARL is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNARL; see file COPYING.  If not, write --
-- to  the Free Software Foundation,  59 Temple Place - Suite 330,  Boston, --
-- MA 02111-1307, USA.                                                      --
--                                                                          --
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNARL was developed by the GNARL team at Florida State University. It is --
-- now maintained by Ada Core Technologies Inc. in cooperation with Florida --
-- State University (http://www.gnat.com).                                  --
--                                                                          --
------------------------------------------------------------------------------

--  This is the FreeBSD PTHREADS version of this package.  Contributed
--  by Daniel M. Eischen (deischen@iworks.InterWorks.org).

with Interfaces.C;
--  used for int
--           size_t

with System.Error_Reporting;
--  used for Shutdown

with System.Interrupt_Management;
--  used for Keep_Unmasked
--           Abort_Task_Interrupt
--           Interrupt_ID

with System.Interrupt_Management.Operations;
--  used for Set_Interrupt_Mask
--           All_Tasks_Mask
pragma Elaborate_All (System.Interrupt_Management.Operations);

with System.OS_Interface;
--  used for various type, constant, and operations

with System.Parameters;
--  used for Size_Type

with System.Tasking;
--  used for Ada_Task_Control_Block
--           Task_ID

with Unchecked_Conversion;
with Unchecked_Deallocation;

package body System.Task_Primitives.Operations is

   use System.Tasking;
   use Interfaces.C;
   use System.Error_Reporting;
   use System.OS_Interface;
   use System.Parameters;

   pragma Linker_Options ("-lc_r");

   ------------------
   --  Local Data  --
   ------------------

   --  The followings are logically constants, but need to be initialized
   --  at run time.

   ATCB_Key : aliased pthread_key_t;
   --  Key used to find the Ada Task_ID associated with a thread

   Unblocked_Signal_Mask : aliased sigset_t;
   --  The set of signals that should unblocked in all tasks

   -----------------------
   -- Local Subprograms --
   -----------------------

   procedure Abort_Handler
     (signo   : Signal;
      code    : Interfaces.C.int;
      context : access struct_sigcontext);

   function To_Task_ID is new Unchecked_Conversion (System.Address, Task_ID);

   function To_Address is new Unchecked_Conversion (Task_ID, System.Address);

   -------------------
   -- Abort_Handler --
   -------------------

   --  Target-dependent binding of inter-thread Abort signal to
   --  the raising of the Abort_Signal exception.

   --  The technical issues and alternatives here are essentially
   --  the same as for raising exceptions in response to other
   --  signals (e.g. Storage_Error).  See code and comments in
   --  the package body System.Interrupt_Management.

   --  Some implementations may not allow an exception to be propagated
   --  out of a handler, and others might leave the signal or
   --  interrupt that invoked this handler masked after the exceptional
   --  return to the application code.

   --  GNAT exceptions are originally implemented using setjmp()/longjmp().
   --  On most UNIX systems, this will allow transfer out of a signal handler,
   --  which is usually the only mechanism available for implementing
   --  asynchronous handlers of this kind.  However, some
   --  systems do not restore the signal mask on longjmp(), leaving the
   --  abort signal masked.

   --  Alternative solutions include:

   --       1. Change the PC saved in the system-dependent Context
   --          parameter to point to code that raises the exception.
   --          Normal return from this handler will then raise
   --          the exception after the mask and other system state has
   --          been restored (see example below).
   --       2. Use siglongjmp()/sigsetjmp() to implement exceptions.
   --       3. Unmask the signal in the Abortion_Signal exception handler
   --          (in the RTS).

   --  The following procedure would be needed if we can't lonjmp out of
   --  a signal handler.  (See below.)
   --  procedure Raise_Abort_Signal is
   --  begin
   --     raise Standard'Abort_Signal;
   --  end if;

   procedure Abort_Handler
     (signo   : Signal;
      code    : Interfaces.C.int;
      context : access struct_sigcontext) is

      T : Task_ID := Self;
      Result  : Interfaces.C.int;
      Old_Set : aliased sigset_t;

   begin
      --  Assuming it is safe to longjmp out of a signal handler, the
      --  following code can be used:

      if T.Deferral_Level = 0
        and then T.Pending_ATC_Level < T.ATC_Nesting_Level then

         --  Make sure signals used for RTS internal purpose are unmasked

         Result := pthread_sigmask
           (SIG_UNBLOCK, Unblocked_Signal_Mask'Access, Old_Set'Access);
         pragma Assert (Result = 0
           or else Shutdown ("GNULLI failure---Enter_Task (pthread_sigmask)"));
         raise Standard'Abort_Signal;
      end if;

      --  Otherwise, something like this is required:
      --  if not Abort_Is_Deferred.all then
      --    --  Overwrite the return PC address with the address of the
      --    --  special raise routine, and "return" to that routine's
      --    --  starting address.
      --    Context.PC := Raise_Abort_Signal'Address;
      --    return;
      --  end if;

   end Abort_Handler;

   ----------
   -- Self --
   ----------

   function Self return Task_ID is
      Result : System.Address;

   begin
      Result := pthread_getspecific (ATCB_Key);
      pragma Assert (Result /= System.Null_Address
        or else Shutdown ("GNULLI failure---pthread_getspecific"));
      return To_Task_ID (Result);
   end Self;

   ---------------------
   -- Initialize_Lock --
   ---------------------

   --  Note: mutexes and cond_variables needed per-task basis are
   --        initialized in Intialize_TCB and the Storage_Error is
   --        handled. Other mutexes (such as All_Tasks_Lock, Memory_Lock...)
   --        used in RTS is initialized before any status change of RTS.
   --        Therefore rasing Storage_Error in the following routines
   --        should be able to be handled safely.

   procedure Initialize_Lock
     (Prio : System.Any_Priority;
      L    : access Lock)
   is
      Attributes : aliased pthread_mutexattr_t;
      Result : Interfaces.C.int;
   begin
      Result := pthread_mutexattr_init (Attributes'Access);
      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_mutexattr_init"));

      if Result = ENOMEM then
         raise STORAGE_ERROR;
      end if;

      Result := pthread_mutex_init (L, Attributes'Access);

      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_mutex_init"));

      if Result = ENOMEM then
         raise STORAGE_ERROR;
      end if;

   end Initialize_Lock;

   procedure Initialize_Lock (L : access RTS_Lock) is
      Attributes : aliased pthread_mutexattr_t;
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutexattr_init (Attributes'Access);
      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_mutexattr_init"));

      if Result = ENOMEM then
         raise STORAGE_ERROR;
      end if;

      Result := pthread_mutex_init (L, Attributes'Access);

      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_mutex_init"));

      if Result = ENOMEM then
         raise STORAGE_ERROR;
      end if;

   end Initialize_Lock;

   -------------------
   -- Finalize_Lock --
   -------------------

   procedure Finalize_Lock (L : access Lock) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutex_destroy (L);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---pthread_mutex_destroy"));
   end Finalize_Lock;

   procedure Finalize_Lock (L : access RTS_Lock) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutex_destroy (L);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---pthread_mutex_destroy"));
   end Finalize_Lock;

   ----------------
   -- Write_Lock --
   ----------------

   procedure Write_Lock (L : access Lock; Ceiling_Violation : out Boolean) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutex_lock (L);
      if Result = 0 then
         Ceiling_Violation := False;
      else
         Ceiling_Violation := Result = EINVAL;
      end if;
      --  assumes the cause of EINVAL is a priority ceiling violation
      pragma Assert (Result = 0 or else Result = EINVAL
          or else Shutdown ("GNULLI failure---pthread_mutex_lock"));
   end Write_Lock;

   procedure Write_Lock (L : access RTS_Lock) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutex_lock (L);
      pragma Assert (Result = 0
          or else Shutdown ("GNULLI failure---pthread_mutex_lock"));
   end Write_Lock;

   procedure Write_Lock (T : Task_ID) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutex_lock (T.LL.L'Access);
      pragma Assert (Result = 0
          or else Shutdown ("GNULLI failure---pthread_mutex_lock"));
   end Write_Lock;

   ---------------
   -- Read_Lock --
   ---------------

   procedure Read_Lock (L : access Lock; Ceiling_Violation : out Boolean) is
   begin
      Write_Lock (L, Ceiling_Violation);
   end Read_Lock;

   ------------
   -- Unlock --
   ------------

   procedure Unlock (L : access Lock) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutex_unlock (L);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---pthread_mutex_unlock"));
   end Unlock;

   procedure Unlock (L : access RTS_Lock) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutex_unlock (L);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---pthread_mutex_unlock"));
   end Unlock;

   procedure Unlock (T : Task_ID) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_mutex_unlock (T.LL.L'Access);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---pthread_mutex_unlock"));
   end Unlock;

   -------------
   --  Sleep  --
   -------------

   procedure Sleep (Self_ID : Task_ID) is
      Result : Interfaces.C.int;

   begin
      pragma Assert (Self_ID = Self
        or else Shutdown ("GNULLI failure---Self in Sleep"));
      Result := pthread_cond_wait (Self_ID.LL.CV'Access, Self_ID.LL.L'Access);
      --  EINTR is not considered a failure.
      pragma Assert (Result = 0 or else Result = EINTR
        or else Shutdown ("GNULLI failure---Sleep"));
   end Sleep;

   ---------------
   -- Sleep_For --
   ---------------

   procedure Sleep_For
     (Self_ID  : Task_ID;
      Rel_Time : Duration;
      Timedout : out Boolean)
   is
   begin
      Sleep_Until (Self_ID, Rel_Time + Clock, Timedout);
   end Sleep_For;

   -----------------
   -- Sleep_Until --
   -----------------

   procedure Sleep_Until
     (Self_ID  : Task_ID;
      Abs_Time : Duration;
      Timedout : out Boolean)
   is
      Request : aliased timespec;
      Result  : Interfaces.C.int;

   begin
      pragma Assert (Self_ID = Self
        or else Shutdown ("GNULLI failure---Self in Sleep_Until"));

      if Abs_Time <= Clock then
         Timedout := True;
         Result := sched_yield;
         return;
      end if;

      Request := To_Timespec (Abs_Time);

      --  We loop until the requested delay is serviced. For early wakeups,
      --  we check the Clock again and re-request delays until we sleep
      --  at least for the specified amount.

      loop
         --  Perform delays until one of the following conditions is true:
         --  1) cond_timedwait wakes up due to time expiration.
         --  2) We were interrupted by an abort signal (abortion is pending).
         --  3) We received a wakeup, via cond_signal to our CV.
         --  4) An error has occurred in the OS-provided delay primitive.
         --  Conditions (1), (2), and (3) are normal.
         --  Condition (4) should never happen unless the OS is broken,
         --  or there is an error in our own runtime system code.

         loop
            Result := pthread_cond_timedwait
              (Self_ID.LL.CV'Access, Self_ID.LL.L'Access, Request'Access);

            if Result = 0 or else
              (Self_ID.Pending_Action and then
                Self_ID.Pending_ATC_Level < Self_ID.ATC_Nesting_Level)
            then
               Timedout := False;
               return;
            else
               --  As of 11/25/97, FreeBSD-3.0 returns the correct
               --  (POSIX specified) code (ETIMEDOUT) for a timed-out
               --  operation.  Previous versions of FreeBSD would
               --  return -1, and set the thread-safe errno to EAGAIN.
               if Result < 0 and then Errno = EAGAIN then
                  Result := ETIMEDOUT;
               end if;
            end if;

            if Result = ETIMEDOUT then
               exit;
            end if;

            pragma Assert (Result /= EINVAL or else
              Shutdown ("GNULLI failure---Sleep_Until (cond_timedwait)"));
         end loop;

         --  Make sure we delayed long enough. If we did, give up the
         --  CPU. Otherwise, request a delay again with unserviced amount
         --  of time.

         if (Abs_Time <= Clock) then
            Timedout := True;
            Result := sched_yield;
            exit;
         else
            Request := To_Timespec (Abs_Time);
         end if;
      end loop;
   end Sleep_Until;

   -----------
   -- Clock --
   -----------

   function Clock return Duration is
      TS     : aliased timespec;
      Result : Interfaces.C.int;

   begin
      Result := clock_gettime (CLOCK_REALTIME, TS'Unchecked_Access);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---clock_gettime"));
      return To_Duration (TS);
   exception
      when others =>
         pragma Assert (Shutdown ("exception in Clock"));
         return 0.0;
   end Clock;

   ------------
   -- Wakeup --
   ------------

   procedure Wakeup (T : Task_ID) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_cond_signal (T.LL.CV'Access);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---Wakeup"));
   end Wakeup;

   -----------
   -- Yield --
   -----------

   procedure Yield is
      Result : Interfaces.C.int;
   begin
      Result := sched_yield;
   end Yield;

   ------------------
   -- Set_Priority --
   ------------------

   --  FreeBSD doesn't have the correct pthread_setschedparam routine
   --  yet.  Instead, pthread_setschedparam is imported from pthread_setprio
   --  which only takes a pthread_t and integer as arguments.
--   procedure Set_Priority (T : Task_ID; Prio : System.Any_Priority) is
--      Result     : Interfaces.C.int;
--      Param      : aliased struct_sched_param;
--   begin
--      T.LL.Current_Priority := Interfaces.C.int (Prio);
--      Param.prio := Interfaces.C.int (Prio);
--
--      Result := pthread_setschedparam (T.LL.Thread, SCHED_FIFO,
--                                       Param'Access);
--      pragma Assert (Result = 0
--        or else Shutdown ("GNULLI failure---Set_Priority"));
--
--   end Set_Priority;
   procedure Set_Priority (T : Task_ID; Prio : System.Any_Priority) is
      Result : Interfaces.C.int;
   begin
      T.LL.Current_Priority := Interfaces.C.int (Prio);

      Result := pthread_setschedparam (T.LL.Thread, Interfaces.C.int (Prio));
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---Set_Priority"));

   end Set_Priority;

   ------------------
   -- Get_Priority --
   ------------------

   function Get_Priority (T : Task_ID) return System.Any_Priority is
   begin
      return System.Any_Priority (T.LL.Current_Priority);
   end Get_Priority;

   ----------------
   -- Enter_Task --
   ----------------

   procedure Enter_Task (Self_ID : Task_ID) is
      Result  : Interfaces.C.int;

   begin

      Self_ID.LL.Thread := pthread_self;

      Result := pthread_setspecific (ATCB_Key, To_Address (Self_ID));
      pragma Assert (Result = 0 or else
        Shutdown ("GNULLI failure---Enter_Task (pthread_setspecific)"));
   end Enter_Task;

   ----------------------
   --  Initialize_TCB  --
   ----------------------

   procedure Initialize_TCB (Self_ID : Task_ID; Succeeded : out Boolean) is
      Mutex_Attr : aliased pthread_mutexattr_t;
      Result : Interfaces.C.int;
      Cond_Attr : aliased pthread_condattr_t;

   begin
      Result := pthread_mutexattr_init (Mutex_Attr'Access);
      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_mutexattr_init"));

      if Result /= 0 then
         Succeeded := False;
         return;
      end if;

      Result := pthread_mutex_init (Self_ID.LL.L'Access, Mutex_Attr'Access);
      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_mutex_init"));

      if Result /= 0 then
         Succeeded := False;
         return;
      end if;

      Result := pthread_condattr_init (Cond_Attr'Access);
      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_condattr_init"));

      if Result /= 0 then
         Result := pthread_mutex_destroy (Self_ID.LL.L'Access);
         pragma Assert (Result = 0
           or else Shutdown ("GNULLI failure---pthread_mutex_destory"));
         Succeeded := False;
         return;
      end if;

      Result := pthread_cond_init (Self_ID.LL.CV'Access, Cond_Attr'Access);
      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_cond_init"));

      if Result /= 0 then
         Result := pthread_mutex_destroy (Self_ID.LL.L'Access);
         pragma Assert (Result = 0
           or else Shutdown ("GNULLI failure---pthread_mutex_destory"));
         Succeeded := False;
         return;
      end if;

      Succeeded := True;

   end Initialize_TCB;

   -----------------
   -- Create_Task --
   -----------------

   procedure Create_Task
     (T          : Task_ID;
      Wrapper    : System.Address;
      Stack_Size : System.Parameters.Size_Type;
      Priority   : System.Any_Priority;
      Succeeded  : out Boolean)
   is
      Attributes          : aliased pthread_attr_t;
      Adjusted_Stack_Size : Interfaces.C.size_t;
      Result              : Interfaces.C.int;

      function Thread_Body_Access is new
        Unchecked_Conversion (System.Address, Thread_Body);

   begin
      if Stack_Size = System.Parameters.Unspecified_Size then
         Adjusted_Stack_Size := Interfaces.C.size_t (2 * Default_Stack_Size);
         --  Let's change the s-parame.adb to give a larger Stack_Size ?????
      else
         if Stack_Size < Size_Type (Minimum_Stack_Size) then
            Adjusted_Stack_Size :=
              Interfaces.C.size_t (Stack_Size + Minimum_Stack_Size);

            --  sum, instead of max:  may be overkill, but should be safe
            --  thr_min_stack is a function call.

            --  Actually, we want to get the Default_Stack_Size and
            --  Minimum_Stack_Size from the file System.Parameters.
            --  Right now the package is not made target specific.
            --  We use our own local definitions for now ???

         else
            Adjusted_Stack_Size := Interfaces.C.size_t (Stack_Size);
         end if;

         --  Ask for 4 extra bytes of stack space so that the ATCB
         --  pointer can be stored below the stack limit, plus extra
         --  space for the frame of Task_Wrapper.  This is so the user
         --  gets the amount of stack requested exclusive of the needs
         --  of the runtime.

      end if;

      Adjusted_Stack_Size := Adjusted_Stack_Size + 4;

      --  Since the initial signal mask of a thread is inherited from the
      --  creator, we need to set our local signal mask mask all signals
      --  during the creation operation, to make sure the new thread is
      --  not disturbed by signals before it has set its own Task_ID.

      Result := pthread_attr_init (Attributes'Access);
      pragma Assert (Result = 0 or else Result = ENOMEM
        or else Shutdown ("GNULLI failure---pthread_attr_init"));

      if Result /= 0 then
         Succeeded := False;
         return;
      end if;

      --  Create threads detached following email to report@gnat.com
      --  confirming this is correct (should be fixed for GNAT after 3.09).
      --  (Peter Burwood)
      Result := pthread_attr_setdetachstate
        (Attributes'Access, PTHREAD_CREATE_DETACHED);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---pthread_setdetachstate"));

      Result := pthread_attr_setstacksize
        (Attributes'Access, Interfaces.C.size_t (Adjusted_Stack_Size));
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---pthread_attr_setstacksize"));

      --  Since the initial signal mask of a thread is inherited from the
      --  creator, and the Environment task has all its signals masked, we
      --  do not need to manipulate caller's signal mask at this point.
      --  All tasks in RTS will have All_Tasks_Mask initially.

      Result := pthread_create
        (T.LL.Thread'Access,
         Attributes'Access,
         Thread_Body_Access (Wrapper),
         To_Address (T));
      pragma Assert (Result = 0 or else Result = EAGAIN
        or else Shutdown ("GNULLI failure---Create_Task (pthread_create)"));

      Succeeded := Result = 0;

      Set_Priority (T, Priority);

   end Create_Task;

   ------------------
   -- Finalize_TCB --
   ------------------

   procedure Finalize_TCB (T : Task_ID) is
      Result : Interfaces.C.int;
      Tmp    : Task_ID := T;

      procedure Free is new Unchecked_Deallocation
       (Ada_Task_Control_Block, Task_ID);

   begin
      Result := pthread_mutex_destroy (T.LL.L'Access);
      pragma Assert (Result = 0 or else
        Shutdown ("GNULLI failure---Finalize_TCB (pthread_mutex_destroy)"));
      Result := pthread_cond_destroy (T.LL.CV'Access);
      pragma Assert (Result = 0 or else
        Shutdown ("GNULLI failure---Finalize_TCB (pthread_cond_destroy)"));

      --  Following report to report@gnat.com regarding ATCB memory leak
      --  this Free is now called. The answer back from ACT didn't give
      --  the source for a fix, but I calling this Free is sufficient.
      --  (Peter Burwood)
      Free (Tmp);
   end Finalize_TCB;

   ---------------
   -- Exit_Task --
   ---------------

   procedure Exit_Task is
   begin
      pthread_exit (System.Null_Address);
   end Exit_Task;

   ----------------
   -- Abort_Task --
   ----------------

   procedure Abort_Task (T : Task_ID) is
      Result : Interfaces.C.int;

   begin
      Result := pthread_kill (T.LL.Thread,
        Signal (System.Interrupt_Management.Abort_Task_Interrupt));
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---Abort_Task"));
   end Abort_Task;

   ----------------
   -- Initialize --
   ----------------

   procedure Initialize (Environment_Task : Task_ID) is
      act       : aliased struct_sigaction;
      old_act   : aliased struct_sigaction;
      Tmp_Set   : aliased sigset_t;
      Result    : Interfaces.C.int;

   begin

      Enter_Task (Environment_Task);

      --  Install the abort-signal handler

      act.sa_flags := 0;
      act.sa_handler := Abort_Handler'Address;

      Result := sigemptyset (Tmp_Set'Access);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---Initialize (sigemptyset)"));
      act.sa_mask := Tmp_Set;

      Result :=
        sigaction (
          Signal (System.Interrupt_Management.Abort_Task_Interrupt),
          act'Access,
          old_act'Unchecked_Access);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---Initialize (sigaction)"));

   end Initialize;

begin
   declare
      Result : Interfaces.C.int;
   begin

      --  pthread_init;
      --  This call is needed for MIT thread library. We wish
      --  we could move this to s-osinte.adb and be executed during
      --  the package elaboration. However, in doing so we get an
      --  elaboration problem.
      
      --  It doesn't appear necessary to call it because pthread_init is
      --  called before any Ada elaboration occurs.

      --  Mask Environment task for all signals. The original mask of the
      --  Environment task will be recovered by Interrupt_Server task
      --  during the elaboration of s-interr.adb.

      System.Interrupt_Management.Operations.Set_Interrupt_Mask
        (System.Interrupt_Management.Operations.All_Tasks_Mask'Access);

      --  Prepare the set of signals that should unblocked in all tasks

      Result := sigemptyset (Unblocked_Signal_Mask'Access);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---Initialize (sigemptyset)"));

      for J in Interrupt_Management.Interrupt_ID loop
         if System.Interrupt_Management.Keep_Unmasked (J) then
            Result := sigaddset (Unblocked_Signal_Mask'Access, Signal (J));
            pragma Assert (Result = 0
              or else Shutdown ("GNULLI failure---Initialize (sigaddset)"));
         end if;
      end loop;

      Result := pthread_key_create (ATCB_Key'Access, null);
      pragma Assert (Result = 0
        or else Shutdown ("GNULLI failure---Initialize (pthread_keycreate)"));
   end;

end System.Task_Primitives.Operations;

------------------------------------------------------------------------------
--                                                                          --
--                GNU ADA RUN-TIME LIBRARY (GNARL) COMPONENTS               --
--                                                                          --
--                S Y S T E M . T A S K _ P R I M I T I V E S               --
--                                                                          --
--                                  S p e c                                 --
--                                                                          --
--                             $Revision: 1.1 $                             --
--                                                                          --
--            Copyright (C) 1991-1997, Free Software Foundation, Inc.       --
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
--  by Daniel M. Eischen (eischen@vigrid.com).

pragma Polling (Off);
--  Turn off polling, we do not want ATC polling to take place during
--  tasking operations. It causes infinite loops and other problems.

with Interfaces.C;
--  used for int
--           size_t

with System.OS_Interface;
--  used for pthread_mutex_t
--           pthread_cond_t
--           pthread_t

package System.Task_Primitives is

   type Lock is limited private;
   --  Should be used for implementation of protected objects.

   type RTS_Lock is limited private;
   --  Should be used inside the runtime system.
   --  The difference between Lock and the RTS_Lock is that the later
   --  one serves only as a semaphore so that do not check for
   --  ceiling violations.

   type Task_Body_Access is access procedure;
   --  Pointer to the task body's entry point (or possibly a wrapper
   --  declared local to the GNARL).

   type Private_Data is limited private;
   --  Any information that the GNULLI needs maintained on a per-task
   --  basis.  A component of this type is guaranteed to be included
   --  in the Ada_Task_Control_Block.

private

   type Lock is new System.OS_Interface.pthread_mutex_t;
   type RTS_Lock is new System.OS_Interface.pthread_mutex_t;

   type Private_Data is record
      Thread : aliased System.OS_Interface.pthread_t;
      pragma Atomic (Thread);
      --  Thread field may be updated by two different threads of control.
      --  (See, Enter_Task and Create_Task in s-taprop.adb).
      --  They put the same value (thr_self value). We do not want to
      --  use lock on those operations and the only thing we have to
      --  make sure is that they are updated in atomic fashion.

      LWP : aliased System.Address;
      --  This field is not relevant on all targets. Currently only SGI and
      --  AiX updates it. The purpose of this field is to provide a better
      --  tasking support on gdb. The order of the two first fields (Thread
      --  and LWP) is important.

      CV : aliased System.OS_Interface.pthread_cond_t;

      L  : aliased RTS_Lock;
      --  Protection for all components is lock L

      Current_Priority : Interfaces.C.int := 0;
      --  Active priority, except that the effects of protected object
      --  priority ceilings are not reflected. This only reflects explicit
      --  priority changes and priority inherited through task activation
      --  and rendezvous.
      --
      --  Ada 95 notes: In Ada 95, this field will be transferred to the
      --  Priority field of an Entry_Calls component when an entry call
      --  is initiated. The Priority of the Entry_Calls component will not
      --  change for the duration of the call. The accepting task can
      --  use it to boost its own priority without fear of its changing in
      --  the meantime.
      --
      --  This can safely be used in the priority ordering
      --  of entry queues. Once a call is queued, its priority does not
      --  change.
      --
      --  Since an entry call cannot be made while executing
      --  a protected action, the priority of a task will never reflect a
      --  priority ceiling change at the point of an entry call.
      --
      --  Protection: Only written by Self, and only accessed when Acceptor
      --  accepts an entry or when Created activates, at which points Self is
      --  suspended.

      Stack_Size : Interfaces.C.size_t;
      --  Requested stack size.
      --  Protection: Only used by Self.
   end record;

end System.Task_Primitives;

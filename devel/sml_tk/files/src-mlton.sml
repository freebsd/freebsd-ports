(* ***************************************************************************
 
   $Source$
 
   Implementation of system-dependend functions for MLton 20070826

   Based on version for SMLNJ 109/110.
   Author: stefan
   (C) 1996, Bremen Institute for Safe Systems, Universitaet Bremen
 
  ************************************************************************** *)

structure SysDep : SYS_DEP
=
struct
    (* from Isabelle --- to be used in Makefiles *)
    fun exportML{init:unit->unit, 
                 banner:string, 
                 imagefile:string} = (TextIO.output (TextIO.stdErr,
                                        "export is not supported.\n"))

    fun setPrintDepth n = ()

   (* Set the terminal to a state suitable for sml_tk. Disables INTR
    * s.t. we can use it to abort functions called from bindings, and 
    * sets up QUIT (CTRL-\) to terminate sml_tk instead. Bits of the
    * following are system-independent, but unfortunately the basis library
    * merely allows you to specfiy signals but not install a handler for them
    * which is bloody useless if you ask me :-) *)

    local open Posix.TTY in

    fun initTTY abort =
	if Posix.ProcEnv.isatty (Posix.FileSys.stdin) then
	 let (* configure TTY driver to have ^\ generate sigQUIT *)
	     val {iflag, oflag, cflag, lflag, cc, ispeed, ospeed} = 
	                 fieldsOf (Posix.TTY.TC.getattr Posix.FileSys.stdin)
	     val nuattr= termios {iflag=iflag, oflag=oflag, cflag=cflag, 
				  lflag=lflag, ispeed=ispeed, ospeed=ospeed,
				  cc=V.update(cc, [(V.quit, Char.chr 28)])}
	 in  Posix.TTY.TC.setattr(Posix.FileSys.stdin, TC.sanow, nuattr)
             (* no signal handlers: MLton only has vtalrm and prof. *)
	 end
	else
	    ()  (* stdin is not a tty *)
    end
 
   fun resetTTY () = ()

   (* Wrap an interrupt handler around a function f *)
   (* Not implemented as we are limited in the signals we can catch. *)
   fun interruptable f i a = f a


   (* This shouldn't be here, but SML/NJ implements Unix.reap incorrectly--
    * it returns Posix.Process.status whereas it should return 
    * OS.Process.Process.status *)
    
    fun exec (s,sl) = 
	let
	    val pr = Unix.execute (s,sl)
	in  case Posix.Process.fromStatus (Unix.reap pr) of 
	     Posix.Process.W_EXITED => true
	   | _                      => false
	end
    
end


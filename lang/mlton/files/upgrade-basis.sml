structure MLton = 
   struct
      open MLton

      structure Platform =
         struct
            fun peek (l, f) = List.find f l
            fun omap (opt, f) = Option.map f opt
            val toLower = String.translate (str o Char.toLower)

            structure Arch =
               struct
                  datatype t = Alpha | AMD64 | ARM | HPPA | IA64 | m68k |
                               MIPS | PowerPC | S390 | Sparc | X86

                  val all = [(Alpha, "Alpha"),
                             (AMD64, "AMD64"),
                             (ARM, "ARM"),
                             (HPPA, "HPPA"),
                             (IA64, "IA64"),
                             (m68k, "m68k"),
                             (MIPS, "MIPS"),
                             (PowerPC, "PowerPC"), 
                             (S390, "S390"),
                             (Sparc, "Sparc"), 
                             (X86, "X86")]

                  fun fromString s =
                     let
                        val s = toLower s
                     in
                        omap (peek (all, fn (_, s') => s = toLower s'), #1)
                     end

                  val host = X86

                  fun toString a = #2 (valOf (peek (all, fn (a', _) => a = a')))
               end

            structure OS =
               struct
                  datatype t = AIX | Cygwin | Darwin | FreeBSD | HPUX | Linux
                             | MinGW | NetBSD | OpenBSD | Solaris

                  val all = [(AIX, "AIX"),
                             (Cygwin, "Cygwin"),
                             (Darwin, "Darwin"),
                             (FreeBSD, "FreeBSD"),
                             (HPUX, "HPUX"),
                             (Linux, "Linux"),
                             (MinGW, "MinGW"),
                             (NetBSD, "NetBSD"),
                             (OpenBSD, "OpenBSD"),
                             (Solaris, "Solaris")]

                  fun fromString s =
                     let
                        val s = toLower s
                     in
                        omap (peek (all, fn (_, s') => s = toLower s'), #1)
                     end

                  val host = FreeBSD

                  fun toString a = #2 (valOf (peek (all, fn (a', _) => a = a')))
               end
         end
   end

;; -*- Mode: Lisp -*-
(declaim (optimize (speed 3)
                   (compilation-speed 0)
                   (safety 0)
                   (debug 0)))
(compile-file "screamer.lisp")
(quit)

--- vm/_ioCode/Z_CLI.io	2005-12-04 23:12:32.000000000 +1300
+++ vm/_ioCode/Z_CLI.io	2005-12-05 21:00:35.000000000 +1300
@@ -35,6 +35,7 @@
 			write(inPrompt)
 			line := stdin readLine
 			result := nil
+			line ifNil(Lobby exit)
 			e := try(result = Lobby doString(line))
 			if (e, e showStack)
 			writeln(outPrompt, result)

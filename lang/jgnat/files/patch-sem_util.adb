--- sem_util.adb.orig	Fri Sep  1 10:14:00 2000
+++ sem_util.adb	Fri Feb  8 21:08:34 2002
@@ -1745,7 +1745,7 @@
       Assoc := First (Governed_By);
       Find_Constraint : loop
          Discrim := First (Choices (Assoc));
-         exit when Chars (Discrim_Name) = Chars (Discrim)
+         exit Find_Constraint when Chars (Discrim_Name) = Chars (Discrim)
            or else (Present (Corresponding_Discriminant (Entity (Discrim)))
                       and then
                     Chars (Corresponding_Discriminant (Entity (Discrim)))

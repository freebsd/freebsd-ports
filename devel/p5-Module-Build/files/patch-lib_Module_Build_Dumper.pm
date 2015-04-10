Description: output data in a stable order
 In order to make builds reproducible, we sort keys when dumping
 data.
Author: Jérémy Bobbio <lunar@debian.org>

--- lib/Module/Build/Dumper.pm
+++ lib/Module/Build/Dumper.pm
@@ -12,7 +12,7 @@ use Data::Dumper;
 sub _data_dump {
   my ($self, $data) = @_;
   return ("do{ my "
-	  . Data::Dumper->new([$data],['x'])->Purity(1)->Terse(0)->Dump()
+	  . Data::Dumper->new([$data],['x'])->Purity(1)->Terse(0)->Sortkeys(1)->Dump()
 	  . '$x; }')
 }
 

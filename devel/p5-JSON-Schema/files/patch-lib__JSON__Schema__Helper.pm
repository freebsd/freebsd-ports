--- ./lib/JSON/Schema/Helper.pm.orig	2014-05-21 15:43:01.000000000 -0400
+++ ./lib/JSON/Schema/Helper.pm	2014-05-21 15:49:17.000000000 -0400
@@ -308,12 +308,12 @@
 				if ((defined $schema->{'minimumCanEqual'} and not $schema->{'minimumCanEqual'})
 				or  $schema->{'exclusiveMinimum'})
 				{
-					$addError->("must be greater than minimum value '" . $schema->{'minimum'}) . "'"
+					$addError->("must be greater than minimum value '" . $schema->{'minimum'} . "'")
 						if $value lt $schema->{'minimum'};
 				}
 				else
 				{
-					$addError->("must be greater than or equal to minimum value '" . $schema->{'minimum'}) . "'"
+					$addError->("must be greater than or equal to minimum value '" . $schema->{'minimum'} . "'")
 						if $value le $schema->{'minimum'};
 				}
 			}
@@ -336,12 +336,12 @@
 				if ((defined $schema->{'maximumCanEqual'} and not $schema->{'maximumCanEqual'})
 				or  $schema->{'exclusiveMaximum'})
 				{
-					$addError->("must be less than or equal to maximum value '" . $schema->{'maximum'}) . "'"
+					$addError->("must be less than or equal to maximum value '" . $schema->{'maximum'} . "'")
 						if $value gt $schema->{'maximum'};
 				}
 				else
 				{
-					$addError->("must be less than or equal to maximum value '" . $schema->{'maximum'}) . "'"
+					$addError->("must be less than or equal to maximum value '" . $schema->{'maximum'} . "'")
 						if $value ge $schema->{'maximum'};
 				}
 			}

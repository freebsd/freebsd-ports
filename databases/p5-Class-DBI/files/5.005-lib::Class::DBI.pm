--- lib/Class/DBI.pm~	Tue Mar 16 17:01:40 2004
+++ lib/Class/DBI.pm	Tue Mar 16 17:02:02 2004
@@ -153,7 +153,7 @@
 		my ($class, $alias) = split /=/, shift, 2;
 		my $table = $class ? $class->table : $self->table;
 		$cmap{ $alias || $table } = $class || ref $self || $self;
-		($alias ||= "") &&= " AS $alias";
+		if ($alias ||= "") { $alias = " AS $alias" };
 		return $table . $alias;
 	};
 

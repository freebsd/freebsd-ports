--- Namazu.pm.orig	Tue Feb 19 14:02:48 2002
+++ Namazu.pm	Tue Jun 18 17:53:11 2002
@@ -142,6 +142,18 @@
 
 It returns ranking number.
 
+=head3 summary
+
+It returns summary.
+
+=head3 title
+
+It returns title.
+
+=head3 author
+
+It returns author.
+
 =head1 COPYRIGHT
 
 Copyright 1999,2000,2001,2002 NOKUBI Takatsugu All rights reserved.
@@ -277,15 +289,14 @@
 }
 
 sub set {
-    my $self = shift;
-    my $score = shift;
-    my $uri = shift;
-    my $date = shift;
-    my $rank = shift;
+    my ($self, $score, $uri, $date, $rank, $summary, $title, $author) = @_;
     $self->{score} = $score;
     $self->{uri} = $uri;
     $self->{date} = $date;
     $self->{rank} = $rank;
+    $self->{summary} = $summary;
+    $self->{title} = $title;
+    $self->{author} = $author;
 }
 
 sub score {
@@ -322,6 +333,33 @@
 	$self->{'rank'} = $rank;
     }
     $self->{'rank'};
+}
+
+sub summary {
+    my $self = shift;
+    if (@_) {
+	my $summary = shift;
+	$self->{'summary'} = $summary;
+    }
+    $self->{'summary'};
+}
+
+sub title {
+    my $self = shift;
+    if (@_) {
+	my $title = shift;
+	$self->{'title'} = $title;
+    }
+    $self->{'title'};
+}
+
+sub author {
+    my $self = shift;
+    if (@_) {
+	my $author = shift;
+	$self->{'author'} = $author;
+    }
+    $self->{'author'};
 }
 
 1;

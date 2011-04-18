--- lib/Mail/SpamAssassin/Plugin/DKIM.pm	(revision 925052)
+++ lib/Mail/SpamAssassin/Plugin/DKIM.pm	(working copy)
@@ -213,6 +213,19 @@
 in the SpamAssassin distribution.  The whitelist score is lower, because
 these are often targets for abuse of public mailers which sign their mail.
 
+=item unwhitelist_from_dkim author@example.com
+
+Removes an email address from def_whitelist_from_dkim and whitelist_from_dkim
+tables, if it exists. Useful for removing undesired default entries from a
+distributed configuration file by a local.cf file or by a C<user_prefs>.
+Note that a parameter is a single email address - currently that address
+is removed regardless of a signing-domain which may have been specified in a
+whitelisting entry.
+
+The specified email address has to match exactly the address previously
+used in a whitelist_from_dkim or def_whitelist_from_dkim directive
+(with an exception that its domain name part is matched case-insensitively).
+
 =item adsp_override domain [signing-practices]
 
 Currently few domains publish their signing practices (RFC 5617 - ADSP),
@@ -362,6 +375,7 @@
       }
       my $address = $1;
       my $sdid = defined $2 ? $2 : '';  # empty implies author domain signature
+      $address =~ s/(\@[^@]*)\z/lc($1)/e; # lowercase the email address domain
       $self->{parser}->add_to_addrlist_rcvd('whitelist_from_dkim',
                                             $address, $sdid);
     }
@@ -381,12 +395,32 @@
       }
       my $address = $1;
       my $sdid = defined $2 ? $2 : '';  # empty implies author domain signature
+      $address =~ s/(\@[^@]*)\z/lc($1)/e; # lowercase the email address domain
       $self->{parser}->add_to_addrlist_rcvd('def_whitelist_from_dkim',
                                             $address, $sdid);
     }
   });
 
   push (@cmds, {
+    setting => 'unwhitelist_from_dkim',
+    type => $Mail::SpamAssassin::Conf::CONF_TYPE_ADDRLIST,
+    code => sub {
+      my ($self, $key, $value, $line) = @_;
+      unless (defined $value && $value !~ /^$/) {
+        return $Mail::SpamAssassin::Conf::MISSING_REQUIRED_VALUE;
+      }
+      unless ($value =~ /^\S+$/) {
+        return $Mail::SpamAssassin::Conf::INVALID_VALUE;
+      }
+      $value =~ s/(\@[^@]*)\z/lc($1)/e;  # lowercase the email address domain
+      $self->{parser}->remove_from_addrlist_rcvd('whitelist_from_dkim',
+                                                 $value);
+      $self->{parser}->remove_from_addrlist_rcvd('def_whitelist_from_dkim',
+                                                 $value);
+    }
+  });
+
+  push (@cmds, {
     setting => 'adsp_override',
     type => $Mail::SpamAssassin::Conf::CONF_TYPE_HASH_KEY_VALUE,
     code => sub {




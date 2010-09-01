*** apps/dnscheck-dispatcher.pl	Tue Jun 29 04:15:59 2010
--- apps/dnscheck-dispatcher.pl	Sun Jul  4 19:22:42 2010
***************
*** 43,49 ****
    %running
    %reaped
    %problem
!   $debug
    $verbose
    $check
    $limit
--- 43,49 ----
    %running
    %reaped
    %problem
!   $user
    $verbose
    $check
    $limit
***************
*** 54,59 ****
--- 54,60 ----
    $exit_timeout
    $savelevel
    %levels
+   $debug
  ];
  
  %running   = ();
***************
*** 75,81 ****
      ERROR    => 4,
      CRITICAL => 5,
  );
! 
  # Kick everything off
  main();
  
--- 76,83 ----
      ERROR    => 4,
      CRITICAL => 5,
  );
! # user to run as
! $user = 'nobody';
  # Kick everything off
  main();
  
***************
*** 124,130 ****
  sub setup {
      my $errfile = $check->config->get("daemon")->{errorlog};
      my $pidfile = $check->config->get("daemon")->{pidfile};
! 
      @saved_argv = @ARGV;    # We'll use this if we're asked to restart ourselves
      GetOptions('debug' => \$debug, 'verbose' => \$verbose);
      openlog($check->config->get("syslog")->{ident},
--- 126,135 ----
  sub setup {
      my $errfile = $check->config->get("daemon")->{errorlog};
      my $pidfile = $check->config->get("daemon")->{pidfile};
!     my $uid;
!     unless ($uid = (getpwnam($user))[2]) {
! 	die "Attempt to run dispatcher as non-existent user or as root\n";
!     }
      @saved_argv = @ARGV;    # We'll use this if we're asked to restart ourselves
      GetOptions('debug' => \$debug, 'verbose' => \$verbose);
      openlog($check->config->get("syslog")->{ident},
***************
*** 149,154 ****
--- 154,161 ----
      open PIDFILE, '>', $pidfile or die "Failed to open PID file: $!";
      print PIDFILE $$;
      close PIDFILE;
+ # become non-root
+     $>= $uid;
      $SIG{CHLD} = \&REAPER;
      $SIG{TERM} = sub { $running = 0 };
      $SIG{HUP}  = sub {

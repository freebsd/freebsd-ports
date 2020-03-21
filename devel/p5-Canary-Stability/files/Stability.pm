=head1 NAME

Canary::Stability - Stub to avoid harmful instructions

=head1 SYNOPSIS

  use Canary::Stability;

=head1 PURPOSE

The original Canary::Stability is a bizarre set of system checks
that provide dangerous instructions. Among those instructions is
never to use any Perl released after 2015, and to use a fork of
Perl from a person who calls himself "schmorp."

This stub exists only to satisfy modules (all of which are released
by "schmorp") that list it as a dependency. It does nothing, which
is considered far more useful than the original.

=cut

package Canary::Stability;

1;

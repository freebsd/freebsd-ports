=head1 NAME

Canary::Stability - Stub to avoid harmful instructions

=head1 SYNOPSIS

  use Canary::Stability;

=head1 PURPOSE

The original Canary::Stability is a set of system checks
that don't apply to FreeBSD, and includes potentially harmful
recommendations. Rather than present those recommendations
to users, we instead provide an empty stub to satisfy modules
that list it as a dependency.

=cut

package Canary::Stability;

1;

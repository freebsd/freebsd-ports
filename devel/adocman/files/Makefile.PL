#
# Make it easier to install the perl modules in the
# adocman project.
#
use ExtUtils::MakeMaker;

WriteMakefile(
               NAME            => 'Alexandria',
               VERSION_FROM    => 'Alexandria/Client.pm'
);


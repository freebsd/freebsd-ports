# Automatic testing Support
#
# Add WITH_TESTING=yes into make.conf:
# - If set, and the port supports it, the software's test suite will be compiled
#   and run during the normal building pipeline between 'stage' and 'package'
#   stages.
# - A port may define TESTING_UNSAFE=yes if its tests are known to fail at the
#   moment.

.if !defined(_TESTING_MK_INCLUDED)
_TESTING_MK_INCLUDED=	yes
TESTING_Include_MAINTAINER=	portmgr@FreeBSD.org

.  if !defined(TESTING_UNSAFE)
_TESTING_PACKAGE_DEP=	test
.  endif

.endif

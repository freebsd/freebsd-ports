# Automatic testing Support
#
# Add WITH_TESTING=yes into make.conf:
# - If set, and the port supports it, the software's test suite will be compiled
#   and run during the normal building pipeline between 'stage' and 'package'
#   stages.

.if !defined(_TESTING_MK_INCLUDED)
_TESTING_MK_INCLUDED=	yes
TESTING_Include_MAINTAINER=	portmgr@FreeBSD.org

_TESTING_PACKAGE_DEP=	test

.endif


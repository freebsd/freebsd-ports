# Shared namespace for angr-related ports.
#
# Feature:	angr
# Usage:	USES=angr[:ARGS]
# Valid ARGS:	binaries, nose
#
# binaries	The port requires the special angr binaries to be present for
#		testing.
# nose		The port is using nosetests for the test target.
#
# Variables, which can be set by the port:
#
# ANGR_VERSION		- The version of the angr project programs.
# ANGR_BINARIES_TAGNAME	- The tagname of the angr binaries.
# ANGR_NOSETESTS	- The path to the nosetests program.
#
# Other information:
# - USES=angr:nose implies USES=python:test unless USES=python has already
#   been specified yet.
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_ANGR_MK)
_INCLUDE_USES_ANGR_MK=	yes

# Arguments validation.
_valid_ARGS=    binaries nose
.  for _arg in ${angr_ARGS}
.    if !${_valid_ARGS:M${_arg}}
IGNORE=	USES=angr: invalid argument: ${_arg}
.    endif
.  endfor

# Set the default angr version for all angr-related ports.
ANGR_VERSION?=		9.0.5405
ANGR_BINARIES_TAGNAME?=	v${ANGR_VERSION}

.  if "${angr_ARGS:Mbinaries}" != ""
USE_GITHUB?=	yes
GH_TUPLE+=	angr:binaries:${ANGR_BINARIES_TAGNAME}:binaries

# Provide the binaries directory where it is expected by the test scripts.
pre-test: angr-provide-test-binaries
angr-provide-test-binaries:
	@${LN} -Fs ${WRKSRC_binaries} ${WRKDIR}/binaries
.  endif # "${angr_ARGS:Mbinaries}" != ""

.  if "${angr_ARGS:Mnose}" != ""
# Ensure that python.mk variables are available.
.    if !${USES:Mpython*}
python_ARGS=	test
_USES_POST+=		python:test
.include "${USESDIR}/python.mk"
.    endif # !${USES:Mpython*}

TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}
TEST_WRKSRC?=	${WRKSRC}/tests

ANGR_NOSETESTS?=	nosetests-${PYTHON_VER}

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${ANGR_NOSETESTS})
.  endif # "${angr_ARGS:Mnose}" != ""

.endif

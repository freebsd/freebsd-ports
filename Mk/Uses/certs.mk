# Handle dependency on the ca_root_nss certificate bundle
#
# Feature:	certs
# Usage:	USES=certs:args
# Valid ARGS:	fetch, build, run, test
#
# At least one argument is required.
#
# fetch		ca_root_nss is added as FETCH_DEPENDS
# build		ca_root_nss is added as BUILD_DEPENDS
# run		ca_root_nss is added as RUN_DEPENDS
# test		ca_root_nss is added as TEST_DEPENDS
#
# Examples:
#	USES=certs:fetch,run	# Use certificates for fetch and runtime
#	USES=certs:build	# Use certificates at build time
#
# MAINTAINER:	yuri@FreeBSD.org

.if !defined(_INCLUDE_USES_CERTS_MK)
_INCLUDE_USES_CERTS_MK=	yes

# certificate bundle location and port
_CERTS_DEP=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

# all valid arguments
_CERTS_ALL_ARGS=	fetch build run test

.  if empty(certs_ARGS)
IGNORE=	USES=certs requires at least one argument (${_CERTS_ALL_ARGS})
.  endif

.  if !empty(certs_ARGS:Nfetch:Nbuild:Nrun:Ntest)
IGNORE=	USES=certs has invalid arguments: ${certs_ARGS}. Valid arguments are: ${_CERTS_ALL_ARGS}
.  endif

# Set dependencies based on arguments
.  if ${certs_ARGS:Mfetch}
FETCH_DEPENDS+=	${_CERTS_DEP}
.  endif

.  if ${certs_ARGS:Mbuild}
BUILD_DEPENDS+=	${_CERTS_DEP}
.  endif

.  if ${certs_ARGS:Mrun}
RUN_DEPENDS+=	${_CERTS_DEP}
.  endif

.  if ${certs_ARGS:Mtest}
TEST_DEPENDS+=	${_CERTS_DEP}
.  endif

.endif # _INCLUDE_USES_CERTS_MK

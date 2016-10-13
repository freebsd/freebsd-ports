# $FreeBSD$
#
# Provide support to use the waf building system
#
# Feature:		waf
# Usage:		USES=waf
#
# It implies USES=python:build automatically is no USES=python has been
# specified yet
#
# WAF_CMD		can be specified in the ports if the waf script is not
# 			in WRKSRC/waf
# CONFIGURE_TARGET	default to 'configure'
# ALL_TARGET		default to 'build'
# INSTALL_TARGET=	default to 'install'

.if !defined(_INCLUDE_USES_WAF_MK)
_INCLUDE_USES_WAF_MK=	yes

.if !empty(waf_ARGS)
IGNORE=	Incorrect 'USES+= waf:${waf_ARGS}' waf takes no arguments
.endif

.if !${USES:Mpython*}
python_ARGS=	2,build
.include "${USESDIR}/python.mk"
.endif

MAKEFILE=	#
MAKE_FLAGS=	#
ALL_TARGET=	#
HAS_CONFIGURE=	yes
MAKE_ARGS+=	--verbose
WAF_CMD?=	./waf

CONFIGURE_TARGET?=	configure
ALL_TARGET?=		build
INSTALL_TARGET?=	install

CONFIGURE_CMD=	${PYTHON_CMD} ${WAF_CMD} ${CONFIGURE_TARGET}
MAKE_CMD=	${PYTHON_CMD} ${WAF_CMD}
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			${_MAKE_JOBS}

DESTDIRNAME=	--destdir

# Set a minimal job of 1
_MAKE_JOBS=	-j${MAKE_JOBS_NUMBER}

.endif

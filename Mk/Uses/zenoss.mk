# $FreeBSD$
#
# bsd.zenoss.mk - Support for Zenoss ports and Zenpacks.
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them yourself.
#
# Feature:      zenoss
# Usage:        USES=zenoss
# Valid ARGS:   does not require args
#
# MAINTAINER: zenoss@experts-exchange.com

.if !defined(_INCLUDE_ZENOSS_MK)
_INCLUDE_ZENOSS_MK=    yes

.if defined(zenoss_ARGS)
IGNORE= USES=zenoss does not require args
.endif

BUILD_DEPENDS+=	zenoss>=3.1.0:${PORTSDIR}/net-mgmt/zenoss
RUN_DEPENDS+=	zenoss>=3.1.0:${PORTSDIR}/net-mgmt/zenoss

FETCH_ARGS?=	-o - > ${DISTDIR}/${DISTFILES}

PKGNAMEPREFIX:=	zenpack-${ZPACKGROUP}-

.if !defined(ZPACKGROUP)
IGNORE=			will not work with undefined ZPACKGROUP (ex: core,community,etc)
.endif
ZENHOME=		${LOCALBASE}/zenoss
ZENHOME_REL=		${ZENHOME:S,${LOCALBASE}/,,}
ZPACKHOME=		${LOCALBASE}/zenoss/ZenPack
ZPACKPREFIX?=	ZenPacks.zenoss.
ZPACK?=	${ZPACKPREFIX}${PORTNAME}-${PORTVERSION}-${PYTHON_VERSION:S/thon//}.egg
PLIST_SUB+=		ZPACK=${ZPACK}
SUB_LIST+=		ZENHOME=${ZENHOME} \
				ZPACK=${ZPACK} \
				ZPACKHOME=${ZPACKHOME} \
				ZPACKPREFIX=${ZPACKPREFIX} \
				PORTNAME=${PORTNAME}
SUB_FILES+=		pkg-message pkg-deinstall

SHAREOWN=		zenoss
SHAREGRP=		zenoss

# zenoss provides its own python 2.6 - we build against that for
# application compatibility
PYTHON_VERSION=	python2.6
PYTHON_CMD=		${ZENHOME}/bin/python
PYSETUP=		./setup.py

MAKE_ENV+=		ZENHOME=${ZENHOME} \
				INSTANCE_HOME=${ZENHOME} \
				PYTHONPATH=${ZENHOME}/lib/python \
				PATH=${ZENHOME}/bin:${PATH} \
				PYTHONDONTWRITEBYTECODE=yes

.if !defined(UID)
UID!=		/usr/bin/id -u
.endif

.if !target(do-build)
do-build:
. if ${UID} != 0 && !defined(INSTALL_AS_USER)
	@${ECHO_MSG} "===>  Switching to root credentials for '${.TARGET}' target"
	@cd ${.CURDIR} && \
		${SU_CMD} "${MAKE} ${__softMAKEFLAGS} ${.TARGET}"
	@${ECHO_MSG} "===>  Returning to user credentials"
. else
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} bdist_egg
. endif
.endif

.if !target(do-install)
do-install:
	${MKDIR} ${ZPACKHOME}
	${INSTALL_DATA} ${WRKSRC}/dist/${ZPACK} ${ZPACKHOME}
	@${CAT} ${PKGMESSAGE}
.endif

.endif

# New ports collection makefile for: trac-bitten
# Date created:                      Oct 26 2009
# Whom:                              Tim Niemueller <tim@niemueller.de>
#
# $FreeBSD$
#

PORTNAME=	bitten
PORTVERSION=	0.6
CATEGORIES=	devel www python
MASTER_SITES=	http://ftp.edgewall.com/pub/bitten/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	Bitten-${PORTVERSION}

MAINTAINER=	tim@niemueller.de
COMMENT=	Continuous integration for Trac

.if defined(MAINTAINER_MODE)
UID_FILES+=	../../UIDs
GID_FILES+=	../../GIDs
.endif
USERS=		bitten-slave
GROUPS=		bitten-slave
BITTEN_UID=	952
BITTEN_GID=	952

OPTIONS=	BITTEN_MASTER "Build bitten master" ON
.include <bsd.port.options.mk>

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
.if defined(WITH_BITTEN_MASTER)
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac
.endif

WRKSRC=		${WRKDIR}/Bitten-${PORTVERSION}
NO_BUILD=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION} \
		ECHO_MSG=${ECHO_MSG}
SUB_LIST+=	PYTHON_CMD=${_PYTHON_CMD} TOUCH=${TOUCH} CHOWN=${CHOWN} \
		RM=${RM} USERS=${USERS}
SUB_FILES+=	pkg-message
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_PKGNAME=	Bitten
PATCH_STRIP=	-p1
USE_RC_SUBR=	bitten-slave

.if defined(WITHOUT_BITTEN_MASTER)
PYDISTUTILS_EXTRA_INSTALLARGS=--without-master
PLIST_SUB+=	MASTER_PORT="@comment " EGG_NAME="BittenSlave"
.else
PLIST_SUB+=	MASTER_PORT="" EGG_NAME="Bitten"
.endif

# reproduce rule here with added PYDISTUTILS_EXTRA_INSTALLARGS
do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} ${PYDISTUTILS_EXTRA_INSTALLARGS}	${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})

post-install:
	@if [ ! -f ${ETCDIR}/bitten-slave.conf ]; then \
		${ECHO} Generating initial configuration in ${ETCDIR}/bitten-slave.conf; \
		${MKDIR} ${ETCDIR}; \
		${SED} -e 's/@DISTRO@/${OPSYS}/g' -e 's/@DISTRO_VERSION@/${OSREL}/g' ${FILESDIR}/bitten-slave.sample > ${ETCDIR}/bitten-slave.conf; \
		${CP} ${FILESDIR}/bitten-slave.sample ${ETCDIR}; \
	fi

.include <bsd.port.mk>

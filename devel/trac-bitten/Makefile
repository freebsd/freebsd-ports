# Created by: Tim Niemueller <tim@niemueller.de>
# $FreeBSD$

PORTNAME=	bitten
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	devel www python
MASTER_SITES=	http://ftp.edgewall.com/pub/bitten/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	Bitten-${PORTVERSION}

MAINTAINER=	tim@niemueller.de
COMMENT=	Continuous integration for Trac

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

.if defined(MAINTAINER_MODE)
UID_FILES+=	../../UIDs
GID_FILES+=	../../GIDs
.endif
USERS=		bitten-slave
GROUPS=		bitten-slave
BITTEN_UID=	952
BITTEN_GID=	952

OPTIONS_DEFINE=	BITTEN_MASTER
BITTEN_MASTER_DESC=	Build bitten master

OPTIONS_DEFAULT=	BITTEN_MASTER

BITTEN_MASTER_RUN_DEPENDS=	tracd:www/trac

NO_BUILD=	yes
NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD} TOUCH=${TOUCH} CHOWN=${CHOWN} \
		RM=${RM:Q} USERS=${USERS}
SUB_FILES+=	pkg-message
PATCH_STRIP=	-p1
USE_RC_SUBR=	bitten-slave

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MBITTEN_MASTER}
PYDISTUTILS_INSTALL_TARGET=	--without-master install
.endif

post-install:
	@${ECHO} Generating initial configuration in ${STAGEDIR}${ETCDIR}/bitten-slave.sample
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${SED} -e 's/@DISTRO@/${OPSYS}/g' -e 's/@DISTRO_VERSION@/${OSREL}/g' ${FILESDIR}/bitten-slave.sample > ${STAGEDIR}${ETCDIR}/bitten-slave.sample

.include <bsd.port.mk>

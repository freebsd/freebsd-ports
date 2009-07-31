# New ports collection makefile for:    opencascade-tutorial
# Date created:                         15 March 2007
# Whom:                                 Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=		opencascade-tutorial
PORTVERSION=		6.3
PORTREVISION=	1
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry
DISTNAME=		opencascade-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	OpenCascade sample tutorial

LIB_DEPENDS=	GLU.1:${PORTSDIR}/graphics/libGLU	\
		TKernel.0:${PORTSDIR}/cad/opencascade

IGNORE=		no instructions to build the tutorial

USE_BZIP2=	yes
USE_GL=		yes
USE_QT_VER=	3
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gl-include=${LOCALBASE}/include	\
		--with-gl-library=${LOCALBASE}/lib	\
		--with-qt-dir=${QTDIR}			\
		--enable-qt-mt				\
		--with-cascade-dir=${CASROOT}
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

WRKSRC=		${WRKDIR}/opencascade-${PORTVERSION}/samples/tutorial
CONFIGURE_LOG=	adm/${OPSYS}/config.log

QTDIR?=		${QT_PREFIX}

LOCCROOT=	OpenCAS
OCCROOT=	${PREFIX}/${LOCCROOT}
CASROOT=	${OCCROOT}/ros
LINSTDIR=	${LOCCROOT}/samples/tutorial
INSTDIR=	${PREFIX}/${LINSTDIR}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	INSTDIR=${INSTDIR}
PLIST_SUB=	INSTDIR=${LINSTDIR}

pre-configure:
	${CHMOD} a+x ${WRKSRC}/${CONFIGURE_SCRIPT}
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'	\
		-e 's|/usr/X11R6|${LOCALBASE}|'			\
		${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${MKDIR} ${INSTDIR}/src  ${INSTDIR}/${OPSYS}/obj	\
		${INSTDIR}/${OPSYS}/bin ${INSTDIR}/${OPSYS}/res	\
		${INSTDIR}/adm/${OPSYS} ${INSTDIR}/res
	${TOUCH} ${INSTDIR}/${OPSYS}/obj/.fake_build
	${INSTALL_DATA} ${WRKSRC}/src/* ${INSTDIR}/src
	${INSTALL_DATA} ${WRKSRC}/res/* ${INSTDIR}/res
	${INSTALL_DATA} ${WRKSRC}/${OPSYS}/res/* ${INSTDIR}/${OPSYS}/res
	${INSTALL_DATA} ${WRKSRC}/adm/${OPSYS}/config.${OPSYS}	\
		${INSTDIR}/adm/${OPSYS}
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/bin/Tutorial	\
		${INSTDIR}/${OPSYS}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/run.sh ${INSTDIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>

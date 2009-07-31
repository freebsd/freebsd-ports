# New ports collection makefile for:   crossvc
# Date created:        1 October 2007
# Whom:                Pietro Cerutti (gahr@gahr.ch)
#
# $FreeBSD$

PORTNAME=	crossvc
PORTVERSION=	1.5.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://lincvs.com/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}-0-generic-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Cross-platform Version Control

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3

WRKSRC=		${WRKDIR}/CrossVC

SUB_FILES=	crossvc

QMAKE?=		${QT_PREFIX}/bin/qmake
QTDIR?=		${QT_PREFIX}

CONFIGURE_ENV=	QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"
MAKE_ENV=	QTDIR="${QTDIR}"

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${QMAKE} -o Makefile lincvs.pro

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/CrossVC/Help/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
.endif
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/CrossVC/ && ${COPYTREE_SHARE} Tools ${DATADIR}/)
	(cd ${WRKSRC}/CrossVC/ && ${COPYTREE_SHARE} Messages ${DATADIR}/)
	${INSTALL_PROGRAM} ${WRKSRC}/CrossVC/crossvc.bin ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/CrossVC/AppRun ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/crossvc ${PREFIX}/bin
	${STRIP_CMD} ${DATADIR}/crossvc.bin

.include <bsd.port.mk>

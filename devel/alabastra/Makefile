# New ports collection makefile for:	alabastra
# Date created:				20 Jun 2007
# Whom:					Yinghong.Liu <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$

PORTNAME=	alabastra
PORTVERSION=	0.2b
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	Alabastra-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	C++ Editor writed with QT4

USE_QT_VER=	4
QT_COMPONENTS=	qmake moc gui xml uic rcc

WRKSRC=		${WRKDIR}/Alabastra-${PORTVERSION}

PLIST_FILES=	bin/alabastra

do-configure:
	( cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} Alabastra.pro )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Alabastra ${PREFIX}/bin/alabastra

.include <bsd.port.mk>

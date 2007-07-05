# New ports collection makefile for:	alabastra
# Date created:				20 Jun 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$

PORTNAME=	alabastra
PORTVERSION=	0.2b
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	Alabastra-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	C++ Editor writen with QT4

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

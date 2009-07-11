# New ports collection makefile for:	alabastra
# Date created:				20 Jun 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$

PORTNAME=	alabastra
PORTVERSION=	0.21b
CATEGORIES=	devel
MASTER_SITES=	SF
DISTNAME=	Alabastra-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Editor writen with QT4

USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build moc_build uic_build rcc_build \
		iconengines
USE_GMAKE=	yes
ALL_TARGET=	Alabastra

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/alabastra

do-configure:
	cd ${WRKSRC} \
	    && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS} Alabastra.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Alabastra ${PREFIX}/bin/alabastra

.include <bsd.port.mk>

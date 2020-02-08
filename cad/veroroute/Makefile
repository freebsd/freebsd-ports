# $FreeBSD$

PORTNAME=	veroroute
DISTVERSIONPREFIX=	V
DISTVERSION=	175
DISTVERSIONSUFFIX=	_Src
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	VeroRoute_${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PCB (printed circuit board) design software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../licenses/license_GPLv3.txt

USES=		compiler:c++11-lang qmake qt:5 zip
USE_QT=		core gui network widgets buildtools_build

WRKSRC=		${WRKDIR}/VeroRoute
WRKSRC_SUBDIR=	Src

PLIST_FILES=	bin/${PORTNAME}

do-install: # https://sourceforge.net/p/veroroute/tickets/17/
	${INSTALL_PROGRAM} ${WRKSRC}/../${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

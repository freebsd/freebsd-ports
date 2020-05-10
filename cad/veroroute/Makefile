# $FreeBSD$

PORTNAME=	veroroute
PORTVERSION=	1.93
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PCB (printed circuit board) design software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../licenses/license_GPLv3.txt

USES=		compiler:c++11-lang qmake qt:5
USE_QT=		core gui network widgets buildtools_build

WRKSRC=		${WRKDIR}/VeroRoute
WRKSRC_SUBDIR=	Src

.include <bsd.port.mk>

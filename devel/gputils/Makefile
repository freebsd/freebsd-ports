# Created by: Samuel Tardieu <sam@rfc1149.net>
# $FreeBSD$

PORTNAME=	gputils
DISTVERSION=	1.5.0-1
CATEGORIES=	devel
MASTER_SITES=	SF/gputils/gputils/${DISTVERSION:C/-.*//}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Utilities for Microchip PIC microcontrollers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	gplink-[0-9]*
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-dependency-tracking --disable-html-doc
USES=		bison:alias gmake tar:bz2
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-.*//}

.include <bsd.port.mk>

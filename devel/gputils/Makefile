PORTNAME=	gputils
DISTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/gputils/gputils/1.5.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for Microchip PIC microcontrollers
WWW=		https://gputils.sourceforge.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	gplink
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-html-doc
USES=		bison:alias gmake tar:bz2
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-.*//}

.include <bsd.port.mk>

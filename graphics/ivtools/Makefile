# Created by: scott
# $FreeBSD$

PORTNAME=	ivtools
PORTVERSION=	1.2.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Drawing editors derived from idraw

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

USES=		imake:env
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--with-tiff=${PREFIX}
CONFIGURE_ENV=	IMAKECPP=${CPP}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
MAKE_ARGS=	ARCH=FREEBSD
USE_XORG=	x11 xaw ice xext

MANCOMPRESSED=	no
MAN1=	idraw.1 iclass.1 drawtool.1 comterp.1 comdraw.1 flipbook.1 graphdraw.1

.include <bsd.port.mk>

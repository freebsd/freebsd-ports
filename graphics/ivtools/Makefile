# Created by: Scott Johnston <scott@accom.com>
# $FreeBSD$

PORTNAME=	ivtools
PORTVERSION=	1.2.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Drawing editors derived from idraw

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

USES=		imake:env gmake
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--with-tiff=${PREFIX}
CONFIGURE_ENV=	IMAKECPP=${CPP}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
MAKE_ARGS=	ARCH="${OPSYS:U}" MAKE="${MAKE_CMD}"
USE_XORG=	x11 xaw ice xext

MANCOMPRESSED=	no
MAN1=	idraw.1 iclass.1 drawtool.1 comterp.1 comdraw.1 flipbook.1 graphdraw.1

.include <bsd.port.mk>

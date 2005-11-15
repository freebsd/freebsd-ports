# Ports collection makefile for:	sswf
# Date created:				Oct 17, 2005
# Whom:					anhot
#
# $FreeBSD$
#

PORTNAME=	sswf
PORTVERSION=	1.7.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sswf
DISTNAME=	sswf-${PORTVERSION}-src

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	A library and script language tool to create Flash movies

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/sswf-${PORTVERSION}
USE_ICONV=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>

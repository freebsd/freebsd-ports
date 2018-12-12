# Created by: brett@peloton.physics.montana.edu
# $FreeBSD$

PORTNAME=	cooledit
DISTVERSION=	3.17.28
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	SUNSITE/apps/editors/X/cooledit

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of utilities, including a GUI editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext gmake libtool python # gettext is linked to despite .mo files having been deleted
GNU_CONFIGURE=	yes
USE_XORG=	x11 xt
USE_LDCONFIG=	yes
USE_GCC=	any
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
CFLAGS+=	-DHAVE_MBRTOWC

OPTIONS_DEFINE=	NEXT_LOOK
NEXT_LOOK_DESC=	Enable NeXT look
NEXT_LOOK_CONFIGURE_ENABLE=	NeXT-look

post-patch:
	@${REINPLACE_CMD} -e 's|po pixmap man|po man|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

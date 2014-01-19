# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mac
PORTVERSION=	0.1.1
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monkey's Audio Codec non-win32 port

LIB_DEPENDS=	libmac.so:${PORTSDIR}/audio/mac \
		libbeep.so:${PORTSDIR}/multimedia/beep-media-player

USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
LIBTOOLIZE_ARGS=--force --copy 
AUTOMAKE_ARGS=	--add-missing --copy 

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	lib/bmp/Input/libbmp-mac.so

post-patch:
	@${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED|| ; \
		 s|@BMP_LIBS@|@GTK_LIBS@|' ${WRKSRC}/src/Makefile.am

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/bmp/Input
	(cd ${WRKSRC}/src/.libs && ${INSTALL_LIB} libbmp-mac.so \
		${STAGEDIR}${PREFIX}/lib/bmp/Input)

.include <bsd.port.mk>

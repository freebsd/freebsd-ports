# Ports collection makefile for:  wormux-devel
# Date created:			  21 November 2006
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wormux
DISTVERSION=	20090228
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
PKGNAMESUFFIX=	-devel

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Wormux game

LIB_DEPENDS=	xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26 \
		png.5:${PORTSDIR}/graphics/png \
		curl.5:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer ttf gfx net
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MANCOMPRESSED=	no
MAN6=	wormux.6

post-patch:
	${REINPLACE_CMD} -e "s,-Werror,," ${WRKSRC}/Makefile.in \
	${WRKSRC}/src/Makefile.in

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>

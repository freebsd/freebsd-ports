# New ports collection makefile for:	libshout
# Date created:				06 Jun 2000
# Whom:					zach@pabst.bendnet.com
#
# $FreeBSD$
#

PORTNAME=	libshout2
PORTVERSION=	2.0
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://www.icecast.org/files/libshout/
DISTNAME=	libshout-${PORTVERSION}

MAINTAINER=	lofi@freebsd.org
COMMENT=	Routines for connecting and transmitting data to the icecast server

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis

CONFIGURE_ENV=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_LIBTOOL_VER=13
CONFLICTS=	libshout-1.0.7
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mpkgconfig}!=""
USE_GNOME+=	pkgconfig
PLIST_SUB+=	WITH_PKGCONFIG=""
.else
CONFIGURE_ARGS+=--disable-pkgconfig
PLIST_SUB+=	WITH_PKGCONFIG="@comment "
.endif

post-configure:
	@ ${REINPLACE_CMD} -e "s|pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g" \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>

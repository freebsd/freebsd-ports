# New ports collection makefile for:	xqf
# Date created:				08 February 1999
# Whom:					steve farrell
#
# $FreeBSD$
#

PORTNAME=	xqf
PORTVERSION=	1.0.5
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A server browser for many popular 3D action games

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

USE_GNOME=	intlhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		xqf.6

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

OPTIONS=	GTK2 "GTK+ 2.0 support" on \
		GEOIP "GeoIP support" on \
		BZIP2 "bzip2 compression" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GTK2)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk2
.else
USE_GNOME+=	gdkpixbuf
.endif

.if !defined(WITHOUT_GEOIP)
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if !defined(WITHOUT_BZIP2)
CONFIGURE_ARGS+=	--enable-bzip2
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xqfdocs.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

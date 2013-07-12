# Created by: steve farrell
# $FreeBSD$

PORTNAME=	xqf
PORTVERSION=	1.0.5
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Server browser for many popular 3D action games

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

USE_GNOME=	intlhack
USES=		gettext
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN6=		xqf.6

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	GTK2 GEOIP BZIP2
OPTIONS_DEFAULT=	GTK2 GEOIP BZIP2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--enable-gtk2
.else
USE_GNOME+=	gdkpixbuf
.endif

.if ${PORT_OPTIONS:MGEOIP}
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
.else
CONFIGURE_ARGS+=	--disable-geoip
.endif

.if ${PORT_OPTIONS:MBZIP2}
CONFIGURE_ARGS+=	--enable-bzip2
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xqfdocs.html ${DOCSDIR}
.endif

.include <bsd.port.mk>

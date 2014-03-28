# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	live-f1
PORTVERSION=	0.2.11
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Native client for the official Formula 1 Live Timing service

LICENSE=	GPLv2

LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon29

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

OPTIONS_DEFINE=	NLS

USES=		pkgconfig gettext:build iconv gmake
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/live-f1 \
		man/man1/live-f1.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.include <bsd.port.mk>

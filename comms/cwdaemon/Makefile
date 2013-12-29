# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	cwdaemon
PORTVERSION=	0.9.4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.chronos.org.uk/download/ \
		    ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio cw (Morse code) keyer daemon

LICENSE=	GPLv2

LIB_DEPENDS=	libcw.so:${PORTSDIR}/comms/unixcw
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc

GNU_CONFIGURE=	yes
USES=		pkgconfig

.include <bsd.port.mk>

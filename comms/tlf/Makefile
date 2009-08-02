# ports collection makefile for:	tlf
# Date created:		10 July 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	tlf
PORTVERSION=	0.9.31
CATEGORIES=	comms hamradio
MASTER_SITES=	http://sharon.esrac.ele.tue.nl/pub/linux/ham/tlf/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	tlf-0.9.31-2

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_AUTOTOOLS=	autoconf:262 libtool:22 aclocal:19 automake:19
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib"
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
OPTIONS=	HAMLIB "Use hamlib" ON

MAN1=		tlf.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_HAMLIB)
LIB_DEPENDS+=	hamlib:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=	--enable-hamlib
.else
CONFIGURE_ARGS+=	--disable-hamlib
.endif

.include <bsd.port.post.mk>

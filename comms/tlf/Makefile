# Created by: db
# $FreeBSD$

PORTNAME=	tlf
PORTVERSION=	0.9.31
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://sharon.esrac.ele.tue.nl/pub/linux/ham/tlf/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	tlf-0.9.31-2

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_AUTOTOOLS=	autoconf aclocal automake
USES=		libtool
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

OPTIONS_DEFINE=	HAMLIB
HAMLIB_DESC=	Use hamlib
OPTION_DEFAULT=	HAMLIB

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHAMLIB}
LIB_DEPENDS+=	libhamlib.so:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=	--enable-hamlib
.else
CONFIGURE_ARGS+=	--disable-hamlib
.endif

.include <bsd.port.post.mk>

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

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio curses based logging program

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_AUTOTOOLS=	autoconf libtool aclocal automake
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib"
LDFLAGS+=	${PTHREAD_LIBS}

OPTIONS_DEFINE=	HAMLIB
HAMLIB_DESC=	Use hamlib
OPTION_DEFAULT=	HAMLIB

MAN1=		tlf.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MHAMLIB}
LIB_DEPENDS+=	libhamlib.so:${PORTSDIR}/comms/hamlib
CONFIGURE_ARGS+=	--enable-hamlib
.else
CONFIGURE_ARGS+=	--disable-hamlib
.endif

.include <bsd.port.post.mk>

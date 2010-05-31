# New ports collection makefile for:	cpmtools
# Date created:		31 January 2008
# Whom:			joerg
#
# $FreeBSD$
#

PORTNAME=	xcpc
PORTVERSION=	20070122
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	pixel@hugbox.org
COMMENT=	A portable Amstrad 464&/664/6128 emulator

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--prefix=${PREFIX}

USE_XORG=	ice
USE_GNOME=	pkgconfig glib20
USE_ICONV=	yes
USE_GETTEXT=	yes

LIB_DEPENDS+=	icui18n:${PORTSDIR}/devel/icu \
		pcre.0:${PORTSDIR}/devel/pcre \
		dsk.5:${PORTSDIR}/emulators/libdsk

OPTIONS=	MOTIF "With Motif widget set" on \
		ATHENA "With Athen widget set" off \
		XSHM "With XShm support" on \
		DEBUG "Turn debugging on" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if defined(WITH_XSHM)
CONFIGURE_ARGS+=--enable-xshm
.else
CONFIGURE_ARGS+=--disable-xshm
.endif

.if defined(WITH_MOTIF)
USE_MOTIF=yes
CONFIGURE_ARGS+=--with-motif1
.else
CONFIGURE_ARGS+=--without-motif1
.endif

.if defined(WITH_ATHENA)
LIB_DEPENDS+=	Xaw.8:${PORTSDIR}/x11-toolkits/libXaw
CONFIGURE_ARGS+=--with-athena
.else
CONFIGURE_ARGS+=--without-athena
.endif

.include <bsd.port.post.mk>

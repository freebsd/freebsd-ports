# New ports collection makefile for:	xmms-eq
# Date created:			13 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	eq
PORTVERSION=	0.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	equ
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-xmms-${PORTVERSION}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	A realtime graphical equalizer plugin for XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15

PLIST_FILES=	lib/xmms/Effect/libeq.so

OPTIONS=	OPTIMIZED_CFLAGS "use optimized C flags" on \
		EXT_INSTRUCTIONS "use MMX/SSE/SSE2 instructions if available" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_EXT_INSTRUCTIONS) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--disable-autodetect
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
post-patch:
	@${REINPLACE_CMD} -e 's|-O3||g; s|-fomit-frame-pointer||g; \
		s|-finline-functions||g; s|-ffast-math||g' ${WRKSRC}/configure
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>

# New ports collection makefile for:	games/abe
# Date created:			8 Aug 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	abe
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abe's Amazing Adventure

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_SDL=	mixer sdl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-data-dir=${DATADIR}

MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

OPTIONS_DEFINE=	GOD_MODE OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS
GOD_MODE_DESC=	Enable God Mode (toggle with 'g')

post-install:
	@${MKDIR} ${DATADIR}
.for d in images maps sounds
	@${CP} -R ${WRKSRC}/${d} ${DATADIR}
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGOD_MODE} || !empty{PORT_OPTIONS:MOPTIMIZED_CFLAGS}
post-patch:
.   if ${PORT_OPTIONS:MGOD_MODE}
	@${REINPLACE_CMD} -e 's|\(#define GOD_MODE\) 0|\1 1|' \
		${WRKSRC}/src/Game.h
.   endif
.   if empty(PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	@${REINPLACE_CMD} -e 's|-O2||g ; \
		s|-fomit-frame-pointer||g ; \
		s|-ffast-math||g ; \
		s|-fexpensive-optimizations||g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.   endif
.endif

.include <bsd.port.mk>

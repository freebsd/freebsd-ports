# New ports collection makefile for:	grafx2
# Date created:				23 Feb 2009
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grafx2
PORTVERSION=	2.3.1781
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A pixelart-oriented bitmap painting program

OPTIONS=	TTF "Enable True Type font support" on \
		LUA "Enable Lua scripting support" off

USE_GMAKE=	yes
USE_SDL=	sdl image
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}/src
CFLAGS+=	-DHAVE_SYS_PARAM_H -DHAVE_SYS_UCRED_H -DHAVE_SYS_MOUNT_H

LIB_DEPENDS=	X11:${PORTSDIR}/x11/libX11 \
		png15:${PORTSDIR}/graphics/png

.include <bsd.port.pre.mk>

.if defined(WITHOUT_TTF)
MAKE_ARGS+=	NOTTF=1
.else
USE_SDL+=	ttf
.endif

.if defined(WITH_LUA)
USE_PKGCONFIG=	yes
USE_LUA=	5.1
.else
MAKE_ARGS+=	NOLUA=1
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^  prefix = .*$$|  prefix = ${PREFIX}|' \
		-e '/scripts\/libs/d' \
		-e 's/CC = gcc/CC ?= gcc/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|macosx|FreeBSD|g' \
		${WRKSRC}/mountlist.c ${WRKSRC}/init.c
	@${REINPLACE_CMD} \
		-e 's|Extract_path(program_dir, argv0);|strcpy(program_dir,"${PREFIX}/bin/");|' \
		${WRKSRC}/setup.c

.include <bsd.port.post.mk>

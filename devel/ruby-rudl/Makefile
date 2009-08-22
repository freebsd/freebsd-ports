# New ports collection makefile for:	RuDL
# Date created:		10 April 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudl
PORTVERSION=	0.8
PORTREVISION=	5
CATEGORIES=	devel ruby
MASTER_SITES=	SF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}
DIST_SUBDIR=	ruby

MAINTAINER=	erik@smluc.org
COMMENT=	A high level library to use SDL from Ruby

USE_SDL=	gfx image mixer ttf sdl
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

#NO_WRKSUBDIR=	yes
CONFIGURE_ARGS=	--with-sdl-config="sdl-config"
INSTALL_TARGET=	site-install

DOCS=	RUDL/audio.html \
	RUDL/cdrom.html \
	RUDL/displaysurface.html \
	RUDL/fonts.html \
	RUDL/index.html \
	RUDL/input.html \
	RUDL/misc.html \
	RUDL/rudl.html \
	RUDL/sfont.gif \
	RUDL/surface.html \
	RUDL/timer.html \
	dokumentat.css \
	howto_install.html \
	howto_use.html \
	index.html \
	rudl.css

EXAMPLES=	samples/*

post-extract:
	@${RUBY} -i -pe 'sub(/\r$$/, "")' \
		${WRKSRC}/*.[ch] \
		${WRKSRC}/extconf.rb

post-patch:
	@${RUBY} -i -pe 'sub(/malloc.h/, "stdlib.h")' \
		${WRKSRC}/bitmask.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODDOCDIR}/RUDL
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${RUBY_MODDOCDIR}/${f}
.endfor
.endif

.include <bsd.port.mk>

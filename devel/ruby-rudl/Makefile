# New ports collection makefile for:	RuDL
# Date created:		10 April 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudl
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	devel ruby
MASTER_SITES=	http://froukepc.dhs.org/rudl/download/antiques/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A high level library to use SDL from Ruby

BROKEN=		"Does not build"

USE_SDL=	image mixer ttf sdl
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-sdl-config="sdl11-config"
INSTALL_TARGET=	site-install

DOCS=		INSTALL.txt LICENSE.txt README.txt WARRANTY.txt

post-patch:
	${RUBY} -i -pe 'gsub %r:\.\./:, ""' ${WRKSRC}/samples/*.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	RuDL
# Date created:		10 April 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rudl
PORTVERSION=	0.7.1
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A high level library to use SDL from Ruby

USE_SDL=	gfx image mixer ttf sdl
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

NO_WRKSUBDIR=	yes
CONFIGURE_ARGS=	--with-sdl-config="sdl11-config"
INSTALL_TARGET=	site-install

DOCS=		README.txt WARRANTY.txt docs/*
EXAMPLES=	samples/*

post-extract:
	${RUBY} -i -pe 'sub(/\r$$/, "")' ${WRKSRC}/*.[ch]

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

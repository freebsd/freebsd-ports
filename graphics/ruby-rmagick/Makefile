# New ports collection makefile for:	RMagick
# Date created:		16 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rmagic
PORTVERSION=	0.9.1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://home.nc.rr.com/rmagick/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	RMagick-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	Magick.5:${PORTSDIR}/graphics/ImageMagick

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		ChangeLog README.txt

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	cd ${WRKSRC}; ${RUBY} makedoc.rb \
		--data-dir ${RUBY_MODDOCDIR} \
		--im-doc-dir ${LOCALBASE}/share/doc/ImageMagick
.endif

.include <bsd.port.mk>

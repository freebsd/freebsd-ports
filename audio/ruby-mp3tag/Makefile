# New ports collection makefile for:	Ruby/Mp3Tag
# Date created:		30 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mp3tag
PORTVERSION=	1.0
CATEGORIES=	audio ruby
MASTER_SITES=	http://users.cybercity.dk/~dsl8950/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby module to manipulate ID3v1.1 tags in MP3 files

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		README	mp3tag.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/mp3tag.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/mp3tag_test.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

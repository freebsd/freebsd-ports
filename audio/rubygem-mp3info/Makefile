# New ports collection makefile for:	Ruby/mp3info
# Date created:		24 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mp3info
PORTVERSION=	0.2.1
CATEGORIES=	audio ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/91/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to access to information on mp3 files

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		doc
#EXAMPLES=	test.rb

post-install:
.if !defined(NOPORTDOCS)
#	${MKDIR} ${RUBY_MODEXAMPLESDIR}
#.for f in ${EXAMPLES}
#	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
#.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

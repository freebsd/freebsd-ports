# New ports collection makefile for:	Ruby/mp3info
# Date created:		24 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mp3info
PORTVERSION=	0.5
CATEGORIES=	audio ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A Ruby library to access to information on mp3 files

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_RDOC=	yes
RUBY_SETUP=	install.rb
CONFIGURE_ARGS=	--prefix=${PREFIX}

DOCS=		CHANGELOG EXAMPLES README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "${DOCS}" ${RUBY_MODDOCDIR}/)
.endif

.include <bsd.port.mk>

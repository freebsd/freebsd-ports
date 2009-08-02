# New ports collection makefile for:	ruby-extensions
# Date created:		3 Jan 2007
# Whom:			Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	extensions
PORTVERSION=	0.6.0
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful extensions for Ruby's standard classes

RUBY_SETUP=	install.rb
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
USE_RUBY_RDOC=	yes

.if !defined(NOPORTDOCS)
USE_RAKE=	yes
.endif

DOCS_EN=	README README.1st build/rdoc/*

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${RAKE_BIN} rerdoc
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	Ruby-locale
# Date created:		11 February 2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	locale2
PORTVERSION=	2.0.5
CATEGORIES=	devel ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	locale
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-locale-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure ruby library which provides basic APIs for localization

CONFLICTS=	${PKGNAMEPREFIX}locale-[0-9]*

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.rdoc ${RUBY_MODDOCDIR}/
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/
	@(cd ${WRKSRC}/samples/ && ${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR}/)
.endif

.include <bsd.port.mk>

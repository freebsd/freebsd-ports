# New ports collection makefile for:	ruby-fastri
# Date created:		16 June 2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	fastri
PORTVERSION=	0.3.1
CATEGORIES=	devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast RDoc documentation browser for ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}"

DOCS=		CHANGES README.en

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>

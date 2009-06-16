# New ports collection makefile for:	ruby-aspectr
# Date created:		08 April 2002
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aspectr
PORTVERSION=	0.3.5
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby libraries for Aspect programming

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		CHANGELOG README TODO

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/aspectr.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/logger.rb ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.mk>

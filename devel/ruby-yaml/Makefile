# New ports collection makefile for:	YAML4R
# Date created:		16 Jul 2002
# Whom:			Stanislav Grozev <tacho@daemonz.org>
#
# $FreeBSD$
#

PORTNAME=	yaml
PORTVERSION=	0.47
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}4r
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}rb-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	tacho@daemonz.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		CHANGELOG README

do-install:
	@cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>

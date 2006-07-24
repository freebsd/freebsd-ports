# New ports collection makefile for:		Programming Ruby--The Book
# Date created:			8 March 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	programmingruby
PORTVERSION=	0.4
CATEGORIES=	lang ruby
MASTER_SITES=	http://dev.rubycentral.com/downloads/files/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ProgrammingRuby-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	The source of the Programming Ruby ("pick-axe") book in XML and HTML

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	*

do-install:
	${MKDIR} ${RUBY_MODDOCDIR}
	@${TAR} -xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} -C ${RUBY_MODDOCDIR}
	@${FIND} ${RUBY_MODDOCDIR}/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${RUBY_MODDOCDIR}/ -type f -exec ${CHOWN} ${SHAREOWN} {} \;

.include <bsd.port.mk>

# New ports collection makefile for:	ruby-usersguide-jp
# Date created:			30 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby-usersguide
PORTVERSION=	980206
CATEGORIES=	japanese lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	doc
DISTNAME=	${SHORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby users guide (Japanese version), in HTML format

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

RUBY_MODNAME=	${PORTNAME}-jp

SHORTNAME=	${PORTNAME:S/usersguide/uguide/}

WRKSRC=		${WRKDIR}/${SHORTNAME}
NO_BUILD=	yes

do-install:
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${RUBY_MODDOCDIR}
	${LN} -fs uguide00.html ${RUBY_MODDOCDIR}/index.html

.include <bsd.port.mk>

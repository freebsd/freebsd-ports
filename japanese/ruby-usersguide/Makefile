# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	ruby-usersguide
PORTVERSION=	980206
CATEGORIES=	japanese lang ruby
MASTER_SITES=	RUBY/doc
DISTNAME=	${SHORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby users guide (Japanese version), in HTML format

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

RUBY_MODNAME=	${PORTNAME}-jp

SHORTNAME=	${PORTNAME:S/usersguide/uguide/}

WRKSRC=		${WRKDIR}/${SHORTNAME}
NO_BUILD=	yes

DEPRECATED=	Does not exist upstream
EXPIRATION_DATE=	2017-01-28

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${RUBY_MODDOCDIR}
	${LN} -fs uguide00.html ${STAGEDIR}${RUBY_MODDOCDIR}/index.html

.include <bsd.port.mk>

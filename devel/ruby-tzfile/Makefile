# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	tzfile
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.a-k-r.org/ruby-tzfile/
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	TZFile handling library for Ruby

OPTIONS_DEFINE=	DOCS

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	tzfile.rb
RUBY_RD_HTML=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/tzfile.rb ${STAGEDIR}${RUBY_SITELIBDIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${RUBY_RD_HTML_FILES} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>

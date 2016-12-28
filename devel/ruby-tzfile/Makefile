# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	tzfile
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.a-k-r.org/ruby-tzfile/
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	TZFile handling library for Ruby

OPTIONS_DEFINE=	DOCS

USE_RUBY=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

DEPRECATED=	Upstream no longer exists
EXPIRATION_DATE=	2017-01-28

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/tzfile.rb ${STAGEDIR}${RUBY_SITELIBDIR}/

.include <bsd.port.mk>

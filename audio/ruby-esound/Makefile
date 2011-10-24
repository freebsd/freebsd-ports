# New ports collection makefile for:	Ruby/EsounD
# Date created:		8 October 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	esound
PORTVERSION=	0.1
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.kokone.to/~kgt/Archive/
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby binding to the EsounD library

LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-EsounD-${PORTVERSION}
INSTALL_TARGET=	site-install

REINPLACE_ARGS=	-i ""

DOCS_EN=	esound-0.2.22.patch
DOCS_JA=	METHODS.ja	README.ja

post-patch:
	${REINPLACE_CMD} -E \
		-e "s,^(require[[:space:]]+')./esd.so('.*),\1esd\2," \
		${WRKSRC}/test/*.rb
	${REINPLACE_CMD} -E \
		-e 's|RSTRING\(([^)]+)\)->len|RSTRING_LEN(\1)|g' \
		-e 's|RSTRING\(([^)]+)\)->ptr|RSTRING_PTR(\1)|g' \
		${WRKSRC}/esd.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${DOCS_JA:S,^,${WRKSRC}/,} ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>

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

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby binding to the EsounD library

LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/ruby-EsounD-${PORTVERSION}
INSTALL_TARGET=	site-install

DOCS_EN=	esound-0.2.22.patch
DOCS_JA=	METHODS.ja	README.ja

post-patch:
	${RUBY} -i -pe 'gsub(%r:\./esd\.so:, "esd")' ${WRKSRC}/test/*.rb

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>

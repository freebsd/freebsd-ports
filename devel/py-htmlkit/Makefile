# Ports collection Makefile for:	py-HtmlKit
# Date created:				06/08/2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=		HtmlKit
PORTVERSION=		1.0
CATEGORIES=		devel python www
MASTER_SITES=		http://www.dekorte.com/Software/Python/HtmlKit/Download/
PKGNAMEPREFIX=		py-
DISTNAME=		HtmlKit
EXTRACT_SUFX=		.tar

MAINTAINER=		kbyanc@posi.net

RUN_DEPENDS=		python1.5:${PORTSDIR}/lang/python15

NO_BUILD=		yes

do-install:
	@${MKDIR} ${PREFIX}/lib/python1.5/site-packages
	@${MKDIR} ${PREFIX}/lib/python1.5/site-packages/HtmlKit/
	@for i in ${WRKSRC}/*.py; do \
	    ${INSTALL_DATA} $$i ${PREFIX}/lib/python1.5/site-packages/HtmlKit; \
	done
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/HtmlKit
	@for i in ${WRKSRC}/Documentation/*; do \
	    ${INSTALL_DATA} $$i ${PREFIX}/share/doc/HtmlKit; \
	done
.endif

.include <bsd.port.mk>

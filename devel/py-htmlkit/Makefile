# Ports collection Makefile for:	py-HtmlKit
# Date created:				06/08/2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=		HtmlKit
PORTVERSION=		1.0
PORTREVISION=		1
CATEGORIES=		devel python www
MASTER_SITES=		http://www.dekorte.com/Software/Python/HtmlKit/Download/
PKGNAMEPREFIX=		py-
DISTNAME=		HtmlKit

MAINTAINER=		kbyanc@posi.net

USE_PYTHON=		yes
PLIST_SUB=		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g}
NO_BUILD=		yes

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/HtmlKit
	@for i in ${WRKSRC}/*.py; do \
	    ${INSTALL_DATA} $$i ${PYTHON_SITELIBDIR}/HtmlKit; \
	done
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PYTHON_SITELIBDIR}/HtmlKit
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/HtmlKit
	@for i in ${WRKSRC}/Documentation/*; do \
	    ${INSTALL_DATA} $$i ${PREFIX}/share/doc/HtmlKit; \
	done
.endif

.include <bsd.port.mk>

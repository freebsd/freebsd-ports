# New ports collection makefile for:   etask
# Date created:                15 December 2004
# Whom:                        Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	etask
PORTVERSION=	0.3.91
PORTREVISION=	2
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://members.chello.at/rene.weichselbaum/ \
		http://dryice.name/computer/FreeBSD/distfiles/

MAINTAINER=	dryice@dryice.name
COMMENT=	Manage your projects or tasks within GNU Emacs

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		xpdf:${PORTSDIR}/graphics/xpdf

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
USE_GHOSTSCRIPT_RUN=	yes

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}a

.if !defined(NOPORTDOCS)
PORTDOCS=	etasktut.pdf gpl.txt README
.endif

do-build:
	cd ${WRKSRC}; ${EMACS_NAME} -batch -no-site-file\
			--eval="(add-to-list 'load-path \"${WRKSRC}\")"\
			-f batch-byte-compile *.el

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

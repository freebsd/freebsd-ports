# New ports collection makefile for:   etask
# Date created:                15 December 2004
# Whom:                        Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	etask
PORTVERSION=	0.3.91
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://members.chello.at/rene.weichselbaum/ \
		http://bsdchat.com/dist/dryice/

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Manage your projects or tasks within GNU Emacs

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		ps2pdf:${PORTSDIR}/print/ghostscript-gnu \
		xpdf:${PORTSDIR}/graphics/xpdf

EMACS_PORT_NAME?=	emacs21

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

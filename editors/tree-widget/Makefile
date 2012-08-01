# New ports collection makefile for:   tree-widget
# Date created:                27 July 2004
# Whom:                        Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	tree-widget
PORTVERSION=	2.0
PORTREVISION=	12
CATEGORIES=	editors elisp
MASTER_SITES=	SF/emhacks/${PORTNAME}/${PORTVERSION} \
		http://dryice.name/computer/FreeBSD/distfiles/

PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tree widget for Emacs

USE_EMACS=	yes

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
NO_WRKSUBDIR=	yes
THEMES_SUBDIR=	default folder

do-build:
	cd ${WRKSRC}; ${EMACS_NAME} -batch -no-site-file\
			--eval="(add-to-list 'load-path \"${WRKSRC}\")"\
			-f batch-byte-compile *.el

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${MKDIR} ${LISPDIR}/tree-widget-themes
.for i in ${THEMES_SUBDIR}
	${MKDIR} ${LISPDIR}/tree-widget-themes/${i}
	${INSTALL_DATA} ${WRKSRC}/tree-widget-themes/${i}/*\
			${LISPDIR}/tree-widget-themes/${i}
.endfor

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} != "emacs23"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

.include <bsd.port.post.mk>

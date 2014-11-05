# Created by: Dryice Liu <dryice@liu.com.cn>
# $FreeBSD$

PORTNAME=	tree-widget
PORTVERSION=	2.0
PORTREVISION=	15
CATEGORIES=	editors elisp
MASTER_SITES=	SF/emhacks/${PORTNAME}/${PORTVERSION} \
		http://dryice.name/computer/FreeBSD/distfiles/

PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tree widget for Emacs

USE_EMACS=	yes

LISPDIR=	${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
NO_WRKSUBDIR=	yes
THEMES_SUBDIR=	default folder

do-build:
	cd ${WRKSRC}; ${EMACS_NAME} -batch -no-site-file\
			--eval="(add-to-list 'load-path \"${WRKSRC}\")"\
			-f batch-byte-compile *.el

do-install:
	@${MKDIR} ${LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.el *.elc ${LISPDIR})
	@${MKDIR} ${LISPDIR}/tree-widget-themes
	(cd ${WRKSRC}/tree-widget-themes && ${COPYTREE_SHARE} "${THEMES_SUBDIR}" \
		${LISPDIR}/tree-widget-themes)

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} != "emacs23"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

.include <bsd.port.post.mk>

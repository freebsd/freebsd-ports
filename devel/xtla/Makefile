# New ports collection makefile for:   xtla
# Date created:                27 June 2004
# Whom:                        Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	xtla
PORTVERSION=	1.2.1
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	devel elisp
MASTER_SITES=	http://download.gna.org/xtla-el/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Emacs front-end to tla

BUILD_DEPENDS+=	tla:${PORTSDIR}/devel/tla \
		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/tree-widget/tree-widget.el:${PORTSDIR}/editors/tree-widget
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_EMACS=	yes

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-emacs=${EMACS_NAME} --with-diff=gdiff --with-patch=gpatch
USE_GMAKE=	yes
INFO=		xtla

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/lisp/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/texinfo/xtla.info ${PREFIX}/info

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ANNOUNCEMENTS BINDINGS FEATURES HACKING TODO
	${INSTALL_DATA} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} != "emacs23"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

.include <bsd.port.post.mk>

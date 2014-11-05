# Created by: Dryice Liu <dryice@liu.com.cn>
# $FreeBSD$

PORTNAME=	xtla
PORTVERSION=	1.2.1
PORTREVISION=	15
PORTEPOCH=	1
CATEGORIES=	devel elisp
MASTER_SITES=	http://download.gna.org/xtla-el/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs front-end to tla

BUILD_DEPENDS+=	tla:${PORTSDIR}/devel/tla \
		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/tree-widget/tree-widget.el:${PORTSDIR}/editors/tree-widget
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_EMACS=	yes

LISPDIR=	${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-emacs=${EMACS_NAME} --with-diff=gdiff --with-patch=gpatch
USES=		gmake makeinfo
INFO=		xtla

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${LISPDIR}
	(cd ${WRKSRC}/lisp && ${INSTALL_DATA} *.el *.elc ${LISPDIR})
	${INSTALL_DATA} ${WRKSRC}/texinfo/xtla.info ${STAGEDIR}${PREFIX}/info
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} ANNOUNCEMENTS BINDINGS FEATURES \
		HACKING TODO ${STAGEDIR}${DOCSDIR})

.include <bsd.port.pre.mk>

.if ${EMACS_PORT_NAME} != "emacs23"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

.include <bsd.port.post.mk>

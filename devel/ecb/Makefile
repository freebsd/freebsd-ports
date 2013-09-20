# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	ecb
PORTVERSION=	2.40
PORTREVISION=	11
CATEGORIES=	devel elisp
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME:U}%20${PORTVERSION}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Emacs Code Browser

USE_EMACS=	yes
USE_GMAKE=	yes

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
ICONSRC=	${WRKSRC}/ecb-images
ICONDIR=	${LISPDIR}/ecb-images
ICONSUBDIRS=	height-10 height-14 height-15 height-16 height-17 height-18 \
		height-19 height-20 height-21

ALL_TARGET=	ecb

INFO=		ecb

OPTIONS_DEFINE=		CEDET ICONS DOCS
OPTIONS_DEFAULT=	CEDET ICONS
CEDET_DESC=	Use the Cedet library

PORTDOCS=	NEWS README RELEASE_NOTES

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCEDET}
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/cedet/common/cedet.el:${PORTSDIR}/devel/cedet
RUN_DEPENDS+=	${BUILD_DEPENDS}
MAKE_ARGS=	CEDET=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/cedet
.else
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/semantic/semantic.el:${PORTSDIR}/devel/semantic
RUN_DEPENDS+=	${BUILD_DEPENDS}
MAKE_ARGS=	CEDET=""
.endif

.if ${PORT_OPTIONS:MICONS}
PLIST_SUB+=	ICONS=""
.else
PLIST_SUB+=	ICONS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} "s|1\ 0\ 4\ 9|1\ 1\ 5\ 0|" ${WRKSRC}/ecb-upgrade.el
	${REINPLACE_CMD} "s|\./info-help|${PREFIX}/info|" ${WRKSRC}/ecb-help.el
	${REINPLACE_CMD} "s/^\(@dircategory \)GNU Emacs Lisp/\1The Emacs editor and associated tools/" ${WRKSRC}/ecb.texi

post-build:
	cd ${WRKSRC} && makeinfo --no-split ecb.texi

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/ecb.info ${PREFIX}/info

.if ${PORT_OPTIONS:MICONS}
.for i in ${ICONSUBDIRS}
	${MKDIR} ${ICONDIR}/default/${i}
	${INSTALL_DATA} ${ICONSRC}/default/${i}/*.xpm ${ICONDIR}/default/${i}
	${MKDIR} ${ICONDIR}/directories/${i}
	${INSTALL_DATA} ${ICONSRC}/directories/${i}/*.xpm \
		${ICONDIR}/directories/${i}
.endfor
	${MKDIR} ${ICONDIR}/methods/height-14_to_21
	${INSTALL_DATA} ${ICONSRC}/methods/height-14_to_21/*.xpm \
		${ICONDIR}/methods/height-14_to_21
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>


# New ports collection makefile for:   ecb
# Date created:                25 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	ecb
PORTVERSION=	2.24
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ecb
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Emacs Code Browser

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/semantic/semantic.el:${PORTSDIR}/devel/semantic${PORTNAMESUFFIX}
RUN_DEPENDS=	${BUILD_DEPENDS}

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
ICONSRC=	${WRKSRC}/ecb-images
ICONDIR=	${LISPDIR}/ecb-images
ICONSUBDIRS=	height-10 height-15 height-16 height-17 height-18 height-19 \
		height-19 height-20 height-21

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CEDET=""
ALL_TARGET=	ecb

.if defined(WITH_ICONS)
PLIST_SUB+=     ICONS=""
.else
PLIST_SUB+=     ICONS="@comment "
.endif

INFO=		ecb

pre-everything::
.if !defined(WITH_ICONS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_ICONS=yes   Install also ecb's icons"
	@${ECHO_MSG} ""
.endif

post-patch:
	${REINPLACE_CMD} "s|\./info-help|${PREFIX}/info|" ${WRKSRC}/ecb-help.el

post-build:
	cd ${WRKSRC} && makeinfo --no-split ecb.texi

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/ecb.info ${PREFIX}/info

.if defined(WITH_ICONS)
.for i in ${ICONSUBDIRS}
	${MKDIR} ${ICONDIR}/default/${i}
	${INSTALL_DATA} ${ICONSRC}/default/${i}/*.xpm ${ICONDIR}/default/${i}
	${MKDIR} ${ICONDIR}/directories/${i}
	${INSTALL_DATA} ${ICONSRC}/directories/${i}/*.xpm \
		${ICONDIR}/directories/${i}
.endfor
	${MKDIR} ${ICONDIR}/methods/height-15_to_21
	${INSTALL_DATA} ${ICONSRC}/methods/height-15_to_21/*.xpm \
		${ICONDIR}/methods/height-15_to_21
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in NEWS README RELEASE_NOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	${ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

# New ports collection makefile for:   ecb
# Date created:                25 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	ecb
PORTVERSION=	2.32
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://bsdchat.com/dist/dryice/
MASTER_SITE_SUBDIR=	ecb
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	Emacs Code Browser

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
ICONSRC=	${WRKSRC}/ecb-images
ICONDIR=	${LISPDIR}/ecb-images
ICONSUBDIRS=	height-10 height-14 height-15 height-16 height-17 height-18 \
		height-19 height-20 height-21

USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	ecb

.if defined(WITHOUT_CEDET)
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/semantic/semantic.el:${PORTSDIR}/devel/semantic${PORTNAMESUFFIX}
MAKE_ARGS=	CEDET=""
.else
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/cedet/common/cedet.el:${PORTSDIR}/devel/cedet${PORTNAMESUFFIX}
MAKE_ARGS=	CEDET=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/cedet
.endif

RUN_DEPENDS+=	${BUILD_DEPENDS}

.if defined(WITHOUT_ICONS)
PLIST_SUB+=	ICONS="@comment "
.else
PLIST_SUB+=	ICONS=""
.endif

INFO=		ecb

.if !defined(NOPORTDOCS)
PORTDOCS=	NEWS README RELEASE_NOTES
.endif

pre-everything::
.if !defined(WITHOUT_ICONS)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITHOUT_ICONS=yes   Don't install ecb's icons"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITHOUT_CEDET=yes   Don't use the CEDET library,"
	@${ECHO_MSG} "                      use the old version of "
	@${ECHO_MSG} "                      eieio/semantic/speedbar instead."
	@${ECHO_MSG} ""
.endif

post-patch:
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

.if !defined(WITHOUT_ICONS)
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

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	install-info --dir ${PREFIX}/info/dir ${PREFIX}/info/ecb.info

.include <bsd.port.mk>

# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	onew
PORTVERSION=	2.2.10
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Japan/onew/ \
		ftp://ftp.leo.chubu.ac.jp/pub/editor/jvim/
DISTNAME=	jvim2.0r+${PORTNAME}${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A library for Japanese Input Methods

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=
PORTDOCS=	README.ONEW

OPTIONS_DEFINE=	CANNA CANNA_FREEWNN CANNA_WNN6 CANNA_WNN7 FREEWNN WNN6 WNN7
OPTIONS_DEFAULT=CANNA CANNA_FREEWNN CANNA_WNN6 CANNA_WNN7 FREEWNN WNN6 WNN7
CANNA_DESC=		Build Canna-backend library
CANNA_FREEWNN_DESC=	Build Canna+FreeWnn-backend library
CANNA_WNN6_DESC=	Build Canna+Wnn6-backend library
CANNA_WNN7_DESC=	Build Canna+Wnn7-backend library
FREEWNN_DESC=		Build FreeWnn-backend library
WNN6_DESC=		Build Wnn6-backend library
WNN7_DESC=		Build Wnn7-backend library

LIB_DEPENDS.CANNA=	canna.1:${PORTSDIR}/japanese/canna-lib
BUILD_DEPENDS.CANNA_FREEWNN=	${BUILD_DEPENDS.FREEWNN}
BUILD_DEPENDS.CANNA_WNN6=	${BUILD_DEPENDS.WNN6}
BUILD_DEPENDS.CANNA_WNN7=	${BUILD_DEPENDS.WNN7}
RK_DIR.CANNA_WNN6=	${RKDIR.WNN6}
RK_DIR.CANNA_WNN7=	${RKDIR.WNN7}

BUILD_DEPENDS.FREEWNN=	${LOCALBASE}/lib/libjd.a:${PORTSDIR}/japanese/FreeWnn-lib
BUILD_DEPENDS.WNN6=	${BUILD_DEPENDS.FREEWNN}
RK_DIR.WNN6=		${LOCALBASE}/lib/wnn/ja_JP/rk.wnn6

BUILD_DEPENDS.WNN7=	${BUILD_DEPENDS.FREEWNN}
RK_DIR.WNN7=		${LOCALBASE}/lib/wnn/ja_JP/rk.wnn7

NO_STAGE=	yes
.include <bsd.port.options.mk>

.for I in ${OPTIONS_DEFINE:NDOCS}
.if ${PORT_OPTIONS:M${I}}
INPUT_METHOD+=	${I:S/_/+/g:L}
SUB_FILES+=	ONEW_CONF-for-${I:S/_/+/g:L}
PLIST_FILES+=	lib/libonew-${I:S/_/+/g:L}.a
LIB_DEPENDS+=	${LIB_DEPENDS.${I}}
BUILD_DEPENDS+=	${BUILD_DEPENDS.${I}}
RK_DIR+=	${RK_DIR.${I}}
.endif
.endfor

pre-build: apply-slist

do-build:
.for I in ${INPUT_METHOD}
	${INSTALL_DATA} ${WRKDIR}/ONEW_CONF-for-${I} ${WRKSRC}/ONEW_CONF
	cd ${WRKSRC} && ${MAKE} clean && ${MAKE}
	${INSTALL_DATA} ${WRKSRC}/libonew.a ${WRKDIR}/libonew-${I}.a
.endfor

do-install:
.for I in ${INPUT_METHOD}
	${INSTALL_DATA} ${WRKDIR}/libonew-${I}.a ${PREFIX}/lib/libonew-${I}.a
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ONEW ${DOCSDIR}
.endif

.include <bsd.port.mk>

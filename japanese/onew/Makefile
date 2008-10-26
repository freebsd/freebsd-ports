# New ports collection makefile for:	ONEW
# Date created:		5 Sep 1997
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

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

OPTIONS=	CANNA	"Build Canna-backend library" on \
		CANNA_FREEWNN	"Build Canna+FreeWnn-backend library" on \
		CANNA_WNN6	"Build Canna+Wnn6-backend library" on \
		CANNA_WNN7	"Build Canna+Wnn7-backend library" on \
		FREEWNN	"Build FreeWnn-backend library" on \
		WNN6	"Build Wnn6-backend library" on \
		WNN7	"Build Wnn7-backend library" on

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

.include <bsd.port.pre.mk>

.for I in WITH_CANNA WITH_FREEWNN WITH_WNN6 WITH_WNN7 WITH_CANNA_FREEWNN WITH_CANNA_WNN6 WITH_CANNA_WNN7
.if defined(${I})
INPUT_METHOD+=	${I:S/^WITH_//:S/_/+/g:L}
SUB_FILES+=	ONEW_CONF-for-${I:S/^WITH_//:S/_/+/g:L}
PLIST_FILES+=	lib/libonew-${I:S/^WITH_//:S/_/+/g:L}.a
LIB_DEPENDS+=	${LIB_DEPENDS.${I:S/^WITH_//}}
BUILD_DEPENDS+=	${BUILD_DEPENDS.${I:S/^WITH_//}}
RK_DIR+=	${RK_DIR.${I:S/^WITH_//}}
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ONEW ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

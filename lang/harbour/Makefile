# New ports collection makefile for:   harbour
# Date created:        9 May 2003
# Whom:                David G. Holm <harbour@netfang.net>
#
# $FreeBSD$
#

PORTNAME=	harbour
PORTVERSION=	1.0.1
CATEGORIES=	lang
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}-project

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	An open source Clipper-compatible compiler

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

MAKE_JOBS_SAFE=  yes

USE_BISON=	build
USE_GMAKE=	yes

HB_WITHOUT_X11=	yes
HB_ARCHITECTURE=	bsd
HB_COMPILER=		gcc
HB_GT_LIB=			gtsln

HB_BIN_INSTALL=	${LOCALBASE}/bin
HB_DOC_INSTALL=	${DOCSDIR}
HB_LIB_INSTALL=	${LOCALBASE}/lib
HB_INC_INSTALL= ${LOCALBASE}/include

MAKE_ENV+=	HB_ARCHITECTURE=${HB_ARCHITECTURE} \
			HB_COMPILER=${HB_COMPILER} \
			HB_GT_LIB=${HB_GT_LIB} \
			HB_BIN_INSTALL=${HB_BIN_INSTALL} \
			HB_LIB_INSTALL=${HB_LIB_INSTALL} \
			HB_INC_INSTALL=${HB_INC_INSTALL} \
			HB_WITHOUT_X11=${HB_WITHOUT_X11}

.if !defined(NOPORTDOCS)
MAKE_ENV+= HB_DOC_INSTALL=${HB_DOC_INSTALL} 
.endif

PORTDOCS= *.txt genhtm.bat genhtm.lnk genhtm.rsp

do-build:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${SH} ./make_gnu.sh)

pre-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

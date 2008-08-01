# ex:ts=8
# New ports collection makefile for:	lfhex
# Date created:			Jul 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lfhex
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://stoopidsimple.com/files/ \
		http://home.earthlink.net/~eyekode/data/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Large file hex editor

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build qmake_build rcc_build
USE_BISON=	build

PORTDOCS=	README
PLIST_FILES=	bin/lfhex

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^DEFINES|# DEFINES|g' ${WRKSRC}/lfhex.pro
.if ${OSVERSION} >= 700042
	@${REINPLACE_CMD} -e 's| abs| llabs|g' ${WRKSRC}/reader.cpp
.endif

pre-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -unix lfhex.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfhex ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

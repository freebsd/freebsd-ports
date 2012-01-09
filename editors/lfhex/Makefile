# ex:ts=8
# New ports collection makefile for:	lfhex
# Date created:			Jul 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lfhex
PORTVERSION=	0.42
CATEGORIES=	editors
MASTER_SITES=	http://stoopidsimple.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Large file hex editor

LICENSE=	GPLv2

USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build qmake_build rcc_build
USE_BISON=	build
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PORTDOCS=	README
PLIST_FILES=	bin/lfhex
LICENSE_FILES=	${WRKSRC}/../COPYING

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^DEFINES|# DEFINES|g' ${WRKSRC}/lfhex.pro
	@${REINPLACE_CMD} -e 's| abs| llabs|g' ${WRKSRC}/reader.cpp

do-configure:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfhex ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

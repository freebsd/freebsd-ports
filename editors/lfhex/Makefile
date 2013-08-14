# Created by: ijliao
# $FreeBSD$

PORTNAME=	lfhex
PORTVERSION=	0.42
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://stoopidsimple.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Large file hex editor

LICENSE=	GPLv2

USE_QT4=	corelib gui moc_build qmake_build rcc_build
USES=		bison

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

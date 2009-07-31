# New ports collection makefile for:	kcheckers
# Date created: 			2004-01-08
# Whom: 				arved
#
# $FreeBSD$

PORTNAME=	kcheckers
PORTVERSION=	0.6
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://wibix.de/infusions/pro_download_panel/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt version of the classic boardgame checkers

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"

PLIST_FILES=	bin/kcheckers %%DATADIR%%/kcheckers.pdn
PLIST_DIRS=	%%DATADIR%%

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog README
.endif

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e \
		's|/usr/local/share/kcheckers|${DATADIR}|g' kcheckers.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${PREFIX}/share/qt/mkspecs/freebsd-g++ kcheckers.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kcheckers ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/kcheckers.pdn ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

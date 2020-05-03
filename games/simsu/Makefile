# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simsu
PORTVERSION=	1.3.9
CATEGORIES=	games
MASTER_SITES=	https://gottcode.org/${PORTNAME}/ \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Basic Sudoku game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gl qmake qt:5 tar:bzip2
USE_QT=		core gui widgets buildtools_build linguisttools_build
USE_GL=		gl

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch-NLS-off:
	@${REINPLACE_CMD} -e \
		'/INSTALLS/s|qm||' ${WRKSRC}/simsu.pro

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

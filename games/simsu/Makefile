# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simsu
PORTVERSION=	1.3.4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	https://gottcode.org/${PORTNAME}/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Basic Sudoku game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lib qmake tar:bzip2
USE_GL=		gl
USE_QT5=	core gui widgets \
		buildtools_build linguisttools_build

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/simsu.pro

post-patch-NLS-off:
	@${REINPLACE_CMD} -e \
		'/INSTALLS/s|qm||' ${WRKSRC}/simsu.pro

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog NEWS README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

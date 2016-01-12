# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simsu
PORTVERSION=	1.3.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Basic Sudoku game

LICENSE=	GPLv3+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lib qmake tar:bzip2
USE_QT5=	buildtools_build widgets
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' '/qm.files/,/qm.path/s/^/#/' \
		${WRKSRC}/${PORTNAME}.pro
.endif
	@${REINPLACE_CMD} -e \
		's|c++0x|c++11| ; \
		 s|share/man|man|' ${WRKSRC}/simsu.pro

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog NEWS README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

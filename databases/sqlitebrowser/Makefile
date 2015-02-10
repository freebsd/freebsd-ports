# Created by: loïc bartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sqlitebrowser
PORTVERSION=	3.5.1
CATEGORIES=	databases

MAINTAINER=	coder@tuxfamily.org
COMMENT=	DB Browser for SQLite is a visual tool to manage SQLite databases

LICENSE=	MPL GPLv3
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${GH_COMMIT}

USE_GITHUB=	yes
GH_ACCOUNT=	sqlitebrowser
GH_COMMIT=	1d12977
GH_TAGNAME=	${GH_COMMIT}

USES=		cmake desktop-file-utils
USE_QT4=	gui qmake_build linguist_build moc_build uic_build rcc_build
USE_SQLITE=	yes

INSTALLS_ICONS=	yes

post-patch:
	@${ECHO} ${DATADIR}
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/PreferencesDialog.cpp
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/src/Application.cpp

post-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/share/${PORTNAME}/translations
	(cd ${WRKSRC}/translations && ${COPYTREE_SHARE} . ${STAGEDIR}${LOCALBASE}/share/${PORTNAME}/translations)

.include <bsd.port.mk>

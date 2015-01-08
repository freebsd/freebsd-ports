# Created by: loïc bartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	sqlitebrowser
PORTVERSION=	3.4.0
CATEGORIES=	databases

MAINTAINER=	coder@tuxfamily.org
COMMENT=	DB Browser for SQLite is a visual tool to manage SQLite databases

LICENSE=	MPL GPLv3
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${GH_COMMIT}

USE_GITHUB=
GH_ACCOUNT=	sqlitebrowser
GH_COMMIT=	0358faa
GH_TAGNAME=	${GH_COMMIT}

USES=		cmake desktop-file-utils
USE_QT4=	gui qmake_build linguist_build moc_build uic_build rcc_build
USE_SQLITE=	yes

INSTALLS_ICONS=	yes
.include <bsd.port.mk>

# Created by: Sergio Lenzi <lenzi.sergio@gmail.com>
# $FreeBSD$

PORTNAME=	fritzing
PORTVERSION=	0.9.2
DISTVERSIONSUFFIX=	b
PORTREVISION=	19
CATEGORIES=	cad

MAINTAINER=	lenzi.sergio@gmail.com
COMMENT=	CAD for printed circuit boards

LICENSE=	GPLv2+

SUB_FILES+=	pkg-install

USES=		compiler:c++11-lang dos2unix gmake gnome python qmake qt:5 \
		tar:bzip2
USE_QT=		buildtools concurrent core dbus gui imageformats network printsupport qmake serialport sql-sqlite3 svg xml
DOS2UNIX_REGEX=	.*pro
INSTALLS_ICONS=	yes
USE_GITHUB=	yes
GH_PROJECT=	fritzing-app fritzing-parts:parts

PORTDATA=	*
MAKE_ENV=	INSTALL_ROOT="${STAGEDIR}"

BUILD_DEPENDS+=	boost-libs>1.52:devel/boost-libs

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

post-extract:
	cd ${WRKSRC_parts};\
	${MKDIR} parts;${MV} -f * parts 2> /dev/null || true;\
	${MKDIR} pdb;${MV} parts/core pdb;${MKDIR} parts/core;\
	${MV} ${WRKSRC}/bins .

post-install:
	cd ${WRKSRC_parts}; ${COPYTREE_SHARE} . ${STAGEDIR}${LOCALBASE}/share/fritzing

.include <bsd.port.mk>

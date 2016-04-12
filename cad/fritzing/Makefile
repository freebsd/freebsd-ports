# Created by: Sergio Lenzi <lenzi.sergio@gmail.com>
# $FreeBSD$

PORTNAME=	fritzing
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	https://github.com/fritzing/fritzing-app/archive/:source \
		https://github.com/fritzing/fritzing-parts/archive/:parts
DISTFILES=	0.9.2b.tar.gz:source 0.9.2b.zip:parts
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	lenzi.sergio@gmail.com
COMMENT=	CAD for printed circuit boards

LICENSE=	GPLv2+

SUB_FILES+=	pkg-install

WRKSRC=		${WRKDIR}/fritzing-app-${PORTVERSION}b

USES=		dos2unix gmake python qmake tar:bzip2
USE_QT5=	buildtools concurrent core dbus gui imageformats network printsupport qmake serialport sql-sqlite3 svg xml
DOS2UNIX_REGEX=	.*pro
INSTALLS_ICONS=	yes

PORTDATA=	*
MAKE_ENV=	INSTALL_ROOT="${STAGEDIR}"

BUILD_DEPENDS+=	boost-libs>1.52:devel/boost-libs

RUN_DEPENDS+=	py${PYTHON_SUFFIX}-sqlite3>0:databases/py-sqlite3

.include <bsd.port.pre.mk>

post-extract:
	cd ${WRKDIR}/fritzing-parts-0.9.2b;\
	${MKDIR} parts;${MV} -f * parts 2> /dev/null || true;\
	${MKDIR} pdb;${MV} parts/core pdb;${MKDIR} parts/core;\
	${MV} ${WRKDIR}/fritzing-app-0.9.2b/bins .

post-install:
	${CP} -rpf ${WRKDIR}/fritzing-parts-0.9.2b/* ${STAGEDIR}${LOCALBASE}/share/fritzing

.include <bsd.port.post.mk>

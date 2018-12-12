# Created by: Henri Michelon
# $FreeBSD$

PORTNAME=	pgworksheet
PORTVERSION=	1.9
PORTREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1695/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Simple PostreSQL GUI front end

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyPgSQL/libpq/__init__.py:databases/py-pyPgSQL@${PY_FLAVOR}

USES=		pgsql python:2.7 tar:bzip2
USE_GNOME=	pygtk2
USE_PYTHON=	distutils autoplist

post-patch:
	${REINPLACE_CMD} -e \
		's|@PIXMAP_PATH@|${PREFIX}/share/pixmaps/pgworksheet|' \
		${WRKSRC}/pgworksheet
	${REINPLACE_CMD} -e \
		's|@LOCALE_PATH@|${PREFIX}/share/locale|' \
		${WRKSRC}/pgworksheet

.include <bsd.port.mk>

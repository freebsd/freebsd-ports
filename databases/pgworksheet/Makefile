# New ports collection makefile for:	pgworksheet
# Date created:				03 Mar. 2005
# Whom:					Henri Michelon
#
# $FreeBSD$
#

PORTNAME=	pgworksheet
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hmichelon@e-cml.org
COMMENT=	Simple PostreSQL GUI front end

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyPgSQL/libpq/__init__.py:${PORTSDIR}/databases/py-pyPgSQL

USE_X_PREFIX=	yes
USE_PGSQL=	yes
USE_BZIP2=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} -e \
		's|@PIXMAP_PATH@|${PREFIX}/share/pixmaps/pgworksheet|' \
		${WRKSRC}/pgworksheet
	${REINPLACE_CMD} -e \
		's|@LOCALE_PATH@|${PREFIX}/share/locale|' \
		${WRKSRC}/pgworksheet

.include <bsd.port.mk>

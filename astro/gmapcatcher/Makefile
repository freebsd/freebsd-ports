# New ports collection makefile for:	gmapcatcher
# Date created:		24 March 2010
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmapcatcher
PORTVERSION=	0.7.5.0
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	http://gmapcatcher.googlecode.com/files/
DISTNAME=	GMapCatcher-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	An offline map viewer

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOME=	pygtk2
PYDISTUTILS_EGGINFO=${DISTNAME}-py${PYTHON_VER}.egg-info

WRKSRC=		${WRKDIR}/${DISTNAME}

MAN1=		mapcatcher.1 \
		mapdownloader.1

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share/pixmaps,${PREFIX}/share/pixmaps,g' \
		${WRKSRC}/gmapcatcher/mapPixbuf.py
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/download.py ${PREFIX}/bin/mapdownloader
	${INSTALL_SCRIPT} ${WRKSRC}/maps.py ${PREFIX}/bin/mapcatcher
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/changelog ${DOCSDIR}
.endif

.include <bsd.port.mk>

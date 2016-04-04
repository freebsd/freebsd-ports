# $FreeBSD$

PORTNAME=	gmapcatcher
PORTVERSION=	0.8.0.4
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	http://gmapcatcher.googlecode.com/files/
DISTNAME=	mapcatcher_${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Offline map viewer

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/g}
USES=		python
USE_GNOME=	pygtk2
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share/pixmaps,${PREFIX}/share/pixmaps,g' \
		${WRKSRC}/gmapcatcher/widgets/mapPixbuf.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mapcatcher ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mapdownloader ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/changelog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

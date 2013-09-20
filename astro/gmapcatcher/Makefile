# $FreeBSD$

PORTNAME=	gmapcatcher
PORTVERSION=	0.8.0.4
CATEGORIES=	astro geography
MASTER_SITES=	http://gmapcatcher.googlecode.com/files/
DISTNAME=	mapcatcher_${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Offline map viewer

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/g}
NO_STAGE=	yes
USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_NOEGGINFO=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}" PYTHON_VER="${PYTHON_VER}"

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share/pixmaps,${PREFIX}/share/pixmaps,g' \
		${WRKSRC}/gmapcatcher/widgets/mapPixbuf.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mapcatcher ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mapdownloader ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/changelog ${DOCSDIR}
.endif

.include <bsd.port.mk>

# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qvge
PORTVERSION=	0.5.5
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Qt Visual Graph Editor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libOGDF.so:math/ogdf

USE_GITHUB=	yes
GH_ACCOUNT=	ArsMasiuk

USES=		compiler:c++11-lang qt:5 xorg
USE_QT=		buildtools_build qmake_build core gui network opengl \
		printsupport widgets x11extras xml
USE_XORG=	x11

MAKE_ARGS=	INSTALL_ROOT=${STAGEDIR}
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/qvgeapp
PORTDOCS=	CHANGES README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} -r ${BUILD_WRKSRC}/3rdParty/ogdf
	@${REINPLACE_CMD} -e '/CONFIG += c++/s,14,11,' ${WRKSRC}/config.pri
	@${REINPLACE_CMD} -e '/^USE_OGDF{/,+4d' ${WRKSRC}/qvgeapp.pro
	@${REINPLACE_CMD} -e '/#include/s,math\.h,cmath,' ${WRKSRC}/qvge/CUtils.cpp

do-configure:
	cd ${CONFIGURE_WRKSRC} && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	treesheets
PORTVERSION=	0.0.20160612
CATEGORIES=	deskutils

MAINTAINER=	lightside@gmx.com
COMMENT=	Free form data organizer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/ZLIB_LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	aardappel
GH_TAGNAME=	c5fb4d0

BUILD_WRKSRC=	${WRKSRC}/src
PACKAGE_VERSION=	\"${PORTVERSION}\"
MAKE_ENV=	PACKAGE_VERSION=${PACKAGE_VERSION:Q}

USES=		compiler:c++11-lib desktop-file-utils
USE_WX=		3.0+

PORTDATA=	images
PORTDOCS=	docs *.html
PORTEXAMPLES=	*

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/treesheets.desktop \
		share/pixmaps/treesheets.png

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|sys->frame->GetPath(L"|(L"${DOCSDIR}/|' \
		${BUILD_WRKSRC}/document.h
	${REINPLACE_CMD} -e 's|wxFileName(exename).GetPath()|L"${DATADIR}"|' \
		${BUILD_WRKSRC}/myframe.h
	${REINPLACE_CMD} -e 's|frame->GetPath(L"examples|(L"${EXAMPLESDIR}|' \
		${BUILD_WRKSRC}/system.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/TS && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/TS/treesheets.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/TS/images/icon32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	(cd ${WRKSRC}/TS && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	(cd ${WRKSRC}/TS/examples && ${COPYTREE_SHARE} "${PORTEXAMPLES}" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

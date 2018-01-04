# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	darknock
PORTVERSION=	0.3.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that can detect edges in images

LICENSE=	GPLv2+

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		qmake
USE_QT4=	gui linguisttools_build moc_build rcc_build uic_build

PORTDOCS=	changelog
PLIST_FILES=	bin/darknock share/pixmaps/darknock.png

DESKTOP_ENTRIES="${PORTNAME}" \
		"" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" \
		"Graphics;Qt;" \
		"true"

OPTIONS_DEFINE=	DOCS NLS

.for lang in fr it pl ro sv tr
NLS_PLIST_FILES+=	%%DATADIR%%/locale/darknock_${lang}.qm
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/darknock|${DATADIR}|g' \
		${WRKSRC}/src/main.cpp

pre-configure:
	@${LRELEASE} ${BUILD_WRKSRC}/${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/locale/*.qm ${STAGEDIR}${DATADIR}/locale

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changelog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smillaenlarger
DISTVERSION=	0.9.0
CATEGORIES=	graphics
MASTER_SITES=	SF/imageenlarger/imageenlarger/SmillaEnlarger%20Release%20${PORTVERSION}/
DISTNAME=	SmillaEnlarger_${PORTVERSION}_source

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Qt-based tool for high-quality image magnification/resizing

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4 zip
USE_QT=		qmake_build moc_build rcc_build uic_build gui

WRKSRC=		${WRKDIR}/${DISTNAME}/SmillaEnlargerSrc

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	ReadMe.rtf WhatsNew.rtf changelog.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SmillaEnlarger \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qrfcview
PORTVERSION=	0.62
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	CENKES BERLIOS
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical RFC viewer

USES=		qmake
USE_QT4=	gui network corelib uic_build moc_build rcc_build
PLIST_FILES=	bin/qRFCView
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/qRFCView ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

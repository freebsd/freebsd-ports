# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pentobi
PORTVERSION=	13.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Computer opponent for the board game Blokus

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake desktop-file-utils shared-mime-info tar:xz
USE_QT5=	core gui widgets svg concurrent \
		qmake_build buildtools_build linguisttools_build

PORTDOCS=	NEWS

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

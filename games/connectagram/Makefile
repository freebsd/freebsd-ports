# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	connectagram
PORTVERSION=	1.2.5
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/connectagram/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Word unscrambling game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lib qmake tar:bzip2
USE_QT5=	buildtools_build core gui linguisttools_build network widgets
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man|;s|metainfo|appdata|' ${WRKSRC}/connectagram.pro
	@${REINPLACE_CMD} -e \
		's|std::lround|lround|' ${WRKSRC}/src/*.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog NEWS README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

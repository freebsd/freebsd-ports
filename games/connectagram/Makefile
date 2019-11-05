# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	connectagram
PORTVERSION=	1.2.9
PORTREVISION=	4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/connectagram/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Word unscrambling game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gl qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build core gui linguisttools_build network widgets

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/connectagram.pro

post-patch-NLS-off:
	@${REINPLACE_CMD} -e \
		'/INSTALLS/s|qm||' ${WRKSRC}/connectagram.pro

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gottet
PORTVERSION=	1.1.7
PORTREVISION=	2
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	https://gottcode.org/gottet/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Tetris clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib qmake qt:5 tar:bzip2
USE_GL=		gl
USE_QT=		core gui widgets \
		buildtools_build linguisttools_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/gottet.pro

post-patch-NLS-off:
	@${REINPLACE_CMD} -e \
		'/INSTALLS/s|qm||' ${WRKSRC}/gottet.pro

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

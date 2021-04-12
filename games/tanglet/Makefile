# Created by: Rusmir Dusko <nemysis@FreeBSD.org>

PORTNAME=	tanglet
PORTVERSION=	1.6.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/tanglet/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Single player word finding game based on Boggle

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		compiler:c++11-lib desktop-file-utils gl pkgconfig qmake \
		qt:5 shared-mime-info tar:bzip2
USE_GL=		gl
USE_QT=		buildtools_build linguisttools_build core gui widgets

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/src/src.pro

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tanglet
PORTVERSION=	1.3.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/tanglet/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Single player word finding game based on Boggle

LICENSE=	GPLv3+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lib qmake tar:bzip2
USE_QT5=	buildtools_build widgets
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|c++0x|c++11| ; \
		 /link_pkgconfig/d ; \
		 s|PKGCONFIG|LIBS| ; \
		 s|zlib|-lz| ; \
		 s|share/man|man|' ${WRKSRC}/tanglet.pro
	@${REINPLACE_CMD} -e \
		's|std::lround|lround|' ${WRKSRC}/src/letter.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog NEWS README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tanglet
PORTVERSION=	1.4.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/tanglet/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Single player word finding game based on Boggle

LICENSE=	GPLv3+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake \
		shared-mime-info tar:bzip2
USE_QT5=	buildtools_build linguisttools_build core gui widgets
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/tanglet.pro

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} CREDITS ChangeLog NEWS README \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

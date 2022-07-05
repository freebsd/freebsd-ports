PORTNAME=	converseen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.9.6
CATEGORIES=	graphics

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use graphics conversion utility

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang magick:7 qt:5 tar:bzip2
USE_QT=		core gui network widgets \
		buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	Faster3ck
GH_PROJECT=	Converseen

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>

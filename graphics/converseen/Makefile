PORTNAME=	converseen
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1.2
CATEGORIES=	graphics

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Easy to use graphics conversion utility
WWW=		https://converseen.sourceforge.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake compiler:c++11-lang desktop-file-utils gl \
		magick:7 qt:6 tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	Faster3ck
GH_PROJECT=	Converseen
USE_GL=		gl
USE_QT=		base tools:build

CMAKE_ARGS=	-DUSE_QT6=yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/converseen

.include <bsd.port.mk>

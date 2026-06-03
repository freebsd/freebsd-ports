PORTNAME=	subprocess.h
DISTVERSION=	g20240720
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Single header process launching solution for C and C++
WWW=		https://github.com/sheredom/subprocess.h

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	sheredom
GH_TAGNAME=	b49c56e9fe214488493021017bf3954b91c7c1f5

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/subprocess.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/subprocess.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>

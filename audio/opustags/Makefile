PORTNAME=	opustags
DISTVERSION=	1.6.0
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	View and edit Ogg Opus comments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		cmake compiler:c++14-lang iconv pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fmang

PLIST_FILES=	bin/opustags \
		man/man1/opustags.1.gz

.include <bsd.port.mk>

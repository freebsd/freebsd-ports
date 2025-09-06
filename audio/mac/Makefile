PORTNAME=	mac
PORTVERSION=	11.42
CATEGORIES=	audio
MASTER_SITES=	https://www.monkeysaudio.com/files/
DISTNAME=	${PORTNAME:tu}_${PORTVERSION:S|.||}_SDK

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Monkey's Audio lossless codec
WWW=		https://www.monkeysaudio.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake dos2unix zip

DOS2UNIX_FILES=	Shared/*.h \
		Source/Console/Console.cpp

NO_WRKSUBDIR=	yes

.include <bsd.port.mk>

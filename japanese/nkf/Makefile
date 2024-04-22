PORTNAME=	nkf
DISTVERSIONPREFIX=	v
DISTVERSION=	2_1_5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES?=	japanese

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Network Kanji code conversion Filter

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/nkf.c

USES=		iconv
USE_GITHUB=	yes
GH_ACCOUNT=	nurse

MAKE_ENV=	MKDIR="${MKDIR}" \
		ICONV_CMD="${ICONV_CMD}"
PLIST_FILES=	bin/nkf share/man/man1/nkf.1.gz share/man/ja/man1/nkf.1.gz

.include <bsd.port.mk>

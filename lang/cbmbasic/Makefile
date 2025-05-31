PORTNAME=	cbmbasic
DISTVERSION=	20221219
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable version of Commodore 64 BASIC
WWW=		https://github.com/mist64/cbmbasic

# Check files cbmbasic.c, plugin.c and runtime.c
LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	mist64
GH_TAGNAME=	352a313

CFLAGS+=	-fcommon

PLIST_FILES=	bin/cbmbasic

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/cbmbasic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

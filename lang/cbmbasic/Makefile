PORTNAME=	cbmbasic
PORTVERSION=	20221219
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable version of Commodore 64 BASIC
WWW=		https://github.com/mist64/cbmbasic

LICENSE=	BSD NONE
# Not really sure about the legal status
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	mist64
GH_TAGNAME=	352a313

CFLAGS+=	-fcommon

PLIST_FILES=	bin/cbmbasic

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/cbmbasic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

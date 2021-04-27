PORTNAME=	cbmbasic
PORTVERSION=	20180708
CATEGORIES=	lang

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Portable version of Commodore 64 BASIC

LICENSE=	BSD NONE
# Not really sure about the legal status
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	mist64
GH_TAGNAME=	89093eba090d6e1c2d2b6e1cb1616dba0ce9c7f6

CFLAGS+=	-fcommon

PLIST_FILES=	bin/cbmbasic

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/cbmbasic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

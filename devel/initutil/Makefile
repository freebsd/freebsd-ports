PORTNAME=	initutil
PORTVERSION=	2.1.b
CATEGORIES=	devel
MASTER_SITES=	http://www.bdsoft.com/dist/
DISTNAME=	${PORTNAME}2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	STL Container Initialization Library

USES=		dos2unix zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DOS2UNIX_FILES=	InitUtil.h

PLIST_FILES=	include/InitUtil.h

do-install:
	@${INSTALL_DATA} ${WRKSRC}/InitUtil.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>

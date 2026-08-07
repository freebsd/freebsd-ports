PORTNAME=	ta-lib
PORTVERSION=	0.7.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	devel finance
MASTER_SITES=	https://github.com/TA-Lib/ta-lib/releases/download/v${PORTVERSION}/

MAINTAINER=	bdheeman@gmail.com
COMMENT=	UNIX, POSIX Library for Technical Analysis
WWW=		https://ta-lib.org/ \
		https://github.com/TA-Lib/ta-lib

LICENSE=	BSD3CLAUSE

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>

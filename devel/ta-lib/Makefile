PORTNAME=	ta-lib
DISTVERSION=	0.8.3
DISTVERSIONSUFFIX=	-src
CATEGORIES=	devel finance
MASTER_SITES=	https://github.com/TA-Lib/ta-lib/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	UNIX, POSIX Library for Technical Analysis
WWW=		https://ta-lib.org/ \
		https://github.com/TA-Lib/ta-lib

LICENSE=	BSD3CLAUSE

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>

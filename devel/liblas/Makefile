# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblas
PORTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	http://trac.liblas.org/raw-attachment/wiki/${PORTVERSION}/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Library For Reading And Writing LAS-Format Data

#USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/liblas-src-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.mk>

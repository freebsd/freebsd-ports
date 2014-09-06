# Created by: roberto
# $FreeBSD$

PORTNAME=	getline
PORTVERSION=	3.9
CATEGORIES=	devel
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}-src

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Small, portable, and easy to use command line library

LICENSE=	BSD

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_LDCONFIG=	yes

MAKE_ENV+=	AR="${AR}"
MAKE_ENV+=	CC="${CC}"
MAKE_ENV+=	INSTALL="${INSTALL}"
MAKE_ENV+=	LN="${LN}"
MAKE_ENV+=	RANLIB="${RANLIB}"
MAKE_ENV+=	INST_INCDIR="${STAGEDIR}${PREFIX}/include"
MAKE_ENV+=	INST_LIBDIR="${STAGEDIR}${PREFIX}/lib"
MAKE_ENV+=	INST_MANDIR="${STAGEDIR}${PREFIX}/man"

.include <bsd.port.mk>

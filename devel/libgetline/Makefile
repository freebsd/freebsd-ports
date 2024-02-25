PORTNAME=	getline
PORTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}-src

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Small, portable, and easy to use command line library

LICENSE=	MIT

USE_LDCONFIG=	yes

MAKE_ENV+=	AR="${AR}" \
		CC="${CC}" \
		INST_INCDIR="${STAGEDIR}${PREFIX}/include" \
		INST_LIBDIR="${STAGEDIR}${PREFIX}/lib" \
		INST_MANDIR="${STAGEDIR}${PREFIX}/share/man" \
		INSTALL="${INSTALL}" \
		LN="${LN}" \
		RANLIB="${RANLIB}"

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

.include <bsd.port.mk>

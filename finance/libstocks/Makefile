# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	libstocks
PORTVERSION=	0.5.0
CATEGORIES=	finance devel
MASTER_SITES=	SF

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	C library which can be used to fetch stocks quotes

USE_LDCONFIG=	yes
REINPLACE_ARGS=	-i ""
MAKE_ENV=	WITHOUT_PROFILE=yes __MAKE_CONF=/dev/null SRCCONF=/dev/null
MAKE_ENV+=	STAGEDIR="${STAGEDIR}"
USES=		uidfix

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
			-e 's/__UNIX__/__unix__/' \
		$$(${GREP} -El '<malloc.h>|__UNIX__' \
			${WRKSRC}/lib/*.c); \

do-build do-install:
.for d in lib client
	cd ${WRKSRC}/$d && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} -j2 \
		-f ${FILESDIR}/Makefile.$d ${.TARGET:S/do-//}
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	xcoral
PORTVERSION=	3.47
CATEGORIES=	editors
MASTER_SITES=	http://xcoral.free.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiwindow mouse-based text editor for X

USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
LIBS+=		-lgnuregex
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's| regex\.c | |g ; \
		 s| -g | |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"regex\.h"|<gnu/regex.h>|g' ${WRKSRC}/bm_search.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

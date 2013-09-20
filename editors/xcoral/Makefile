# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	xcoral
PORTVERSION=	3.47
CATEGORIES=	editors
MASTER_SITES=	http://xcoral.free.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiwindow mouse-based text editor for X

USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lgnuregex"
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's| regex\.c | |g ; \
		 s| -g | |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"regex\.h"|<gnu/regex.h>|g' ${WRKSRC}/bm_search.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>

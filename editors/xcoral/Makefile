# New ports collection makefile for:    xcoral
# Date created:         1995/10/02
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	xcoral
PORTVERSION=	3.44
CATEGORIES=	editors
MASTER_SITES=	http://xcoral.free.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiwindow mouse-based text editor for X

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
CONFIGURE_ENV=	LIBS="-lgnuregex"
PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 502010
GNU_REGEX_H=    gnu/regex.h
.else
GNU_REGEX_H=    gnuregex.h
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's| regex\.c | |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"regex\.h"|<${GNU_REGEX_H}>|g' ${WRKSRC}/bm_search.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	xdms
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	xdms
PORTVERSION=	1.3.2
CATEGORIES=	archivers
MASTER_SITES=	http://zakalwe.fi/~shd/foss/xdms/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Amiga DMS archiver unpacker

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
ALL_TARGET=	xdms

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} "s@-O2 -Wall@$${CFLAGS} -Wall@g" ${WRKSRC}/src/Makefile.in
.if ( ${OSVERSION} < 500000 )
	${REINPLACE_CMD} 's/stdint.h/inttypes.h/' ${WRKSRC}/src/cdata.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xdms ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xdms
	${INSTALL_DATA} ${WRKSRC}/xdms.txt ${PREFIX}/share/doc/xdms
.endif

.include <bsd.port.post.mk>

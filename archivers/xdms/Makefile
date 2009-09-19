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

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	An Amiga DMS archiver unpacker

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
ALL_TARGET=	xdms

PORTDOCS=	xdms.txt
PLIST_FILES=	bin/xdms

post-patch:
	${REINPLACE_CMD} "s@-O2 -Wall@$${CFLAGS} -Wall@g" ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xdms ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

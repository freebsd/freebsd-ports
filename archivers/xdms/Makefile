# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	xdms
PORTVERSION=	1.3.2
CATEGORIES=	archivers
MASTER_SITES=	http://zakalwe.fi/~shd/foss/xdms/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Tool for decompressing Amiga DMS files

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
ALL_TARGET=	xdms

USE_CSTD=	gnu89

PORTDOCS=	xdms.txt
PLIST_FILES=	bin/xdms

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} "s@-O2 -Wall@$${CFLAGS} -Wall@g" ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xdms ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

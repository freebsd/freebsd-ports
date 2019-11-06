# Created by: Sander Vesik <sander@haldjas.folklore.ee>
# $FreeBSD$

PORTNAME=	tclcheck
PORTVERSION=	1.1.13
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/
DISTNAME=	tclCheck-${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Program to check the nesting of parenthesis in tcl scripts

BROKEN=		unfetchable

LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	 dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		alias

PLIST_FILES=	bin/tclCheck \
		man/man1/tclCheck.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} \
	    -e '/^BIN/s|=.*|=${PREFIX}/bin|' \
	    -e '/^CC/s|=.*|=${CC}|' \
	    -e '/^CFLAGS/s|=.*|=${CFLAGS}|' \
	    ${WRKSRC}/Makefile
	${REINPLACE_CMD} \
	    -e '25s|^|#include <unistd.h>|' \
	    ${WRKSRC}/tclCheck.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tclCheck ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tclCheck.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

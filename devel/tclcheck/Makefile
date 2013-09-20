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

LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	 dist-mirror dist-sell pkg-mirror pkg-sell auto-accept	

MAN1=		tclCheck.1
PLIST_FILES=	bin/tclCheck
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

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
	${INSTALL_PROGRAM} ${WRKSRC}/tclCheck ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tclCheck.1 ${MANPREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

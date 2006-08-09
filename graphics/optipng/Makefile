# New ports collection makefile for:	optipng
# Date created:				09 July 2003
# Whom:					Thomas Hurst <freaky@aagh.net>
#
# $FreeBSD$
#

PORTNAME=	optipng
PORTVERSION=	0.5.3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	freaky@aagh.net
COMMENT=	An optimizer for PNG files

BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	scripts/gcc-syslib.mak
ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/optipng
MAN1=		optipng.1
PORTDOCS=	CAVEAT.txt HISTORY.txt TODO.txt USAGE.txt \
		design.html features.html guide.html thanks.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/optipng ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/optipng.1 ${MAN1PREFIX}/man/man1/

post-install:
.ifndef NOPORTDOCS
	${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>

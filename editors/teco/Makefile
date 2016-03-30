# Created by: Stanislav Sedov <stas@core.310.ru>
# $FreeBSD$

PORTNAME=	teco
PORTVERSION=	0398
CATEGORIES=	editors
MASTER_SITES=	http://almy.us/files/
DISTNAME=	tecoclinux${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful and compact editor with nongraphical user interface

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/tecoc${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	# empty

DOCSFILES=	src/readme.1st src/readme.lnx src/changes.txt src/aaout.txt \
		src/problems.txt src/video.txt doc/teco.doc doc/wchart.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tecoc ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

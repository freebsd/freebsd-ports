# Created by: Stanislav Sedov <stas@core.310.ru>
# $FreeBSD$

PORTNAME=	teco
PORTVERSION=	0398
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://almy.us/files/
DISTNAME=	tecoclinux${PORTVERSION}

MAINTAINER=	bob@eager.cx
COMMENT=	Powerful and compact editor with nongraphical user interface

LICENSE=	BSD3CLAUSE

CFLAGS+=	-Wno-pointer-sign -Wno-int-to-pointer-cast
MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/tecoc${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	# empty

SUB_FILES=	teco.1

OPTIONS_DEFINE=	DOCS

DOCSFILES=	src/readme.1st src/readme.lnx src/changes.txt src/aaout.txt \
		src/problems.txt src/video.txt doc/teco.doc doc/wchart.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tecoc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/teco.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

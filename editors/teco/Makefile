# New ports collection makefile for:	teco
# Date created:				Feb 15 2005
# Whom:					Stanislav Sedov <stas@core.310.ru>
#
# $FreeBSD$
#

PORTNAME=	teco
PORTVERSION=	0398
CATEGORIES=	editors
MASTER_SITES=	http://almy.us/files/
DISTNAME=	tecoclinux${PORTVERSION}

MAINTAINER=	stas@core.310.ru
COMMENT=	Powerful and compact editor with nongrafical user interface

MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/tecoc${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src
ALL_TARGET=	#

DOCSFILES=	src/readme.1st src/readme.lnx src/changes.txt src/aaout.txt \
		src/problems.txt src/video.txt doc/teco.doc doc/wchart.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tecoc ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DATADIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	mkcue
PORTVERSION=	1
CATEGORIES=	audio
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Generates CUE sheets from a CD TOC (Table Of Contents)

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.orig
MAKEFILE=	GNUmakefile
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/mkcue

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mkcue ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mkcue

.include <bsd.port.mk>

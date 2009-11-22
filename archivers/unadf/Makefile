# New ports collection makefile for:	unadf
# Date created:				1 October 2000
# Whom:					Per Wigren
#
# $FreeBSD$
#

PORTNAME=	unadf
PORTVERSION=	0.7.9b
PORTREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	http://perso.club-internet.fr/lclevy/adflib/
DISTNAME=	adflib

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracts files from .adf-files used by Amiga emulators

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/unadf
PORTDOCS=	API.txt api_device.html api_dir.html api_env.html api_file.html \
		api_index.html api_native.html api_salv.html api_volume.html
USE_ZIP=	yes
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s@tests lib demo@lib demo@g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|CFLAGS=-I$$(LIBDIR) -O2 -Wall -Wno-uninitialized -pedantic|CFLAGS+= -I$$(LIBDIR)|' \
			${WRKSRC}/Demo/Makefile
	@${REINPLACE_CMD} -e 's|CFLAGS=|CFLAGS+=|' \
			-e 's|-Wall -O2 -pedantic||' \
			-e 's|CC=|CC?=|' \
			${WRKSRC}/Lib/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Demo/unadf ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/Docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

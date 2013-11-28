# Created by: Franz Klammer <klammer@webonaut.com>
# $FreeBSD$

PORTNAME=	png2ico
PORTVERSION=	2002.12.08
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.winterdrache.de/freeware/png2ico/data/
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts PNG files to Windows icon resource files

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}

CPPFLAGS+=	$$(libpng-config --cflags)
LDFLAGS+=	$$(libpng-config --ldflags)

PORTDOCS=	bmp.txt
PLIST_FILES=	bin/png2ico man/man1/png2ico.1.gz

do-build:
	(cd ${WRKSRC} && ${CXX} ${CXXFLAGS} ${CPPFLAGS} -o png2ico \
		png2ico.cpp ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/png2ico ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/png2ico.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: ache
# $FreeBSD$

PORTNAME=	jpeginfo
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate listing and MD5, check jpegs for error, delete broken ones

LICENSE=	GPLv2

USES=		jpeg
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_ARGS=	mandir=${MANPREFIX}/man INSTALL_ROOT=${STAGEDIR}

PLIST_FILES=	bin/jpeginfo man/man1/jpeginfo.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jpeginfo

.include <bsd.port.mk>

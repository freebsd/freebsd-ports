PORTNAME=	jpeginfo
PORTVERSION=	1.7.1
CATEGORIES=	graphics
MASTER_SITES=	https://www.kokkonen.net/tjko/src/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate listing and MD5, check jpegs for error, delete broken ones
WWW=		https://www.kokkonen.net/tjko/projects.html \
		https://github.com/tjko/jpeginfo

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake jpeg localbase

GNU_CONFIGURE=	yes
MAKE_ARGS=	INSTALL_ROOT=${STAGEDIR}

PLIST_FILES=	bin/jpeginfo \
		share/man/man1/jpeginfo.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/jpeginfo

.include <bsd.port.mk>

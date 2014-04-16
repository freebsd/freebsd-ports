# Created by: Jeremy Norris <ishmael127@home.com>
# $FreeBSD$

PORTNAME=	feh
PORTVERSION=	2.10
CATEGORIES=	graphics
MASTER_SITES=	http://feh.finalrewind.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	An image viewer that utilizes Imlib2

LICENSE=	MIT

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libgiblib.so:${PORTSDIR}/graphics/giblib

USE_XORG=	x11 xt xinerama
USES=		gmake perl5 tar:bzip2 shebangfix desktop-file-utils
USE_PERL5=	run
SHEBANG_FILES=	${WRKSRC}/cam/feh-cam

CPPFLAGS+=	-I${LOCALBASE}/include -std=c99
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/feh


.include <bsd.port.mk>

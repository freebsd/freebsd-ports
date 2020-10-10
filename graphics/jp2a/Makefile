# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jp2a
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Converts JPG images to ASCII

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>0:devel/autoconf-archive
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpng16.so:graphics/png

USES=		autoreconf jpeg ncurses pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Talinx

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-curl-config=${LOCALBASE}/bin/curl-config \
		--with-jpeg-prefix=${LOCALBASE}

CONFIGURE_ENV+=	bashcompdir=${STAGEDIR}${PREFIX}/etc/bash_completion.d
MAKE_ENV+=	bashcompdir=${STAGEDIR}${PREFIX}/etc/bash_completion.d

LDFLAGS+=	-lm

PLIST_FILES=	bin/jp2a \
		etc/bash_completion.d/jp2a \
		man/man1/jp2a.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jp2a ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/jp2a.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/bash/jp2a \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d

.include <bsd.port.mk>

PORTNAME=	vimpc
PORTVERSION=	0.09.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Ncurses client for musicpd with vi-like key bindings

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libpcre.so:devel/pcre \
		libcurl.so:ftp/curl

USES=		autoreconf compiler:c++11-lang ncurses pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	boysetsfrog

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-taglib=no

PLIST_FILES=	bin/vimpc \
		man/man1/vimpc.1.gz \
		${DOCSDIR}/help.txt

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/help.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

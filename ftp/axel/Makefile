PORTNAME=	axel
DISTVERSIONPREFIX=	v
DISTVERSION=	2.17.14
CATEGORIES=	ftp

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight CLI download accelerator
WWW=		https://github.com/axel-download-accelerator/axel

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive \
		txt2man:textproc/txt2man

USES=		autoreconf gettext-tools gmake pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	axel-download-accelerator

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS=	--with-ssl=openssl

PLIST_FILES=	bin/axel \
		share/man/man1/axel.1.gz

.include <bsd.port.mk>

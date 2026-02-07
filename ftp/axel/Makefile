PORTNAME=	axel
DISTVERSIONPREFIX=	v
DISTVERSION=	2.17.14
PORTREVISION=	1
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
CONFIGURE_ARGS=	--with-ssl=openssl

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>

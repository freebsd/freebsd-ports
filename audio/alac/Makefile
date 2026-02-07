PORTNAME=	alac
PORTVERSION=	0.0.7
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Apple Lossless Audio Codec
WWW=		https://github.com/mikebrady/alac

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf libtool
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes

GH_ACCOUNT=	mikebrady

OPTIONS_DEFINE=	CONVERTER
CONVERTER_DESC=	Build with command-line utility to read and write audio data
OPTIONS_DEFAULT=CONVERTER

CONVERTER_CONFIGURE_ON=	--enable-example
CONVERTER_EXTRA_PATCHES=${FILESDIR}/extrapatch-convert-utility_Makefile.am

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>

# Created by: stas@FreeBSD.org
# $FreeBSD$

PORTNAME=	libunwind
PORTVERSION=	20200331	# This is the release date on SAVANNAH
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH \
		https://github.com/libunwind/libunwind/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-1.4.0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic stack unwinding library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS= aarch64 amd64 i386

USES=		libtool pathfix pkgconfig

CONFIGURE_ARGS=	ac_cv_path_LATEX2MAN=${TRUE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	ARCH=${ARCH:S|i386|x86|:S|amd64|x86_64|}

.include <bsd.port.mk>

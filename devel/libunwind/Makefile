# Created by: stas@FreeBSD.org
# $FreeBSD$

PORTNAME=	libunwind
PORTVERSION=	20170615	# This is the release date of libunwind 1.2.1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH
DISTNAME=	${PORTNAME}-1.2.1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic stack unwinding library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS= aarch64 amd64 i386

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes
DOCS_CONFIGURE_ON=	ac_cv_path_LATEX2MAN=${TRUE}
DOCS_CONFIGURE_OFF=	--disable-documentation

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LLD_UNSAFE=	yes

PLIST_SUB=	ARCH=${ARCH:S|i386|x86|:S|amd64|x86_64|}

.include <bsd.port.mk>

# Created by: stas@FreeBSD.org
# $FreeBSD$

PORTNAME=	libunwind
PORTVERSION=	20200331	# This is the release date on SAVANNAH
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SAVANNAH \
		https://github.com/libunwind/libunwind/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}-1.4.0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generic stack unwinding library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS= aarch64 amd64 i386 powerpc64 powerpc64le

USES=		compiler:c11 libtool pathfix pkgconfig

CFLAGS_powerpc64=	-maltivec
CFLAGS_powerpc64le=	-maltivec
CONFIGURE_ARGS=	ac_cv_path_LATEX2MAN=${TRUE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	ARCH=${ARCH:S|i386|x86|:S|amd64|x86_64|:C|powerpc64.*|ppc64|}

.include <bsd.port.pre.mk>

.if ! ${ARCH:Mpowerpc64*}
PLIST_SUB+=	COREDUMP=""
.else
PLIST_SUB+=	COREDUMP="@comment "
.endif

.include <bsd.port.post.mk>

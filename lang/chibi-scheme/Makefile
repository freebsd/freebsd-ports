# Created by: Tobias Kortkamp <tobias.kortkamp@gmail.com>
# $FreeBSD$

PORTNAME=	chibi-scheme
DISTVERSION=	0.8
CATEGORIES=	lang

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Minimal Scheme implementation for use as a C extension language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	ashinn

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ARGS=	IMAGE_FILES="" \
		LDCONFIG=${TRUE} \
		LIBDIR=${PREFIX}/lib \
		MANDIR=${PREFIX}/man/man1 \
		MODDIR=${PREFIX}/lib/chibi \
		PKGCONFDIR=${PREFIX}/libdata/pkgconfig
# tries to generate meta files with ./chibi-scheme when it's not yet built
MAKE_JOBS_UNSAFE=	yes

ALL_TARGET=	all libchibi-scheme.a
TEST_TARGET=	test

PORTSCOUT=	skipv:stable

post-patch:
	@${REINPLACE_CMD} -e 's@ -g -g3 -O3 @ @' \
		-e '/$$(SO)/ s@$$(INSTALL_EXE) -m0755 @$$(BSD_INSTALL_LIB) @' \
		-e '/tools/ s@$$(INSTALL) -m0755 @$$(BSD_INSTALL_SCRIPT) @' \
		-e 's@$$(INSTALL_EXE) -m0755 @$$(BSD_INSTALL_PROGRAM) @' \
		-e '/$$(MANDIR)/ s@$$(INSTALL) -m0644 @$$(BSD_INSTALL_MAN) @' \
		-e 's@$$(INSTALL) -m0644 @$$(BSD_INSTALL_DATA) @' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>

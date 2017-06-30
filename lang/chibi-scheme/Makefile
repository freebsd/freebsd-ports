# Created by: Tobias Kortkamp <tobias.kortkamp@gmail.com>
# $FreeBSD$

PORTNAME=	chibi-scheme
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Minimal Scheme implementation for use as a C extension language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	ashinn

USES=		gmake
USE_LDCONFIG=	yes

MAKE_ARGS=	MODDIR=${PREFIX}/lib/chibi \
		MANDIR=${PREFIX}/man/man1 \
		LIBCHIBI_FLAGS='-Wl,-soname="libchibi-scheme.so.${PORTVERSION}"'

ALL_TARGET=	all libchibi-scheme.a
TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's@ -g -g3 -O3 @ @' \
		-e 's@$$(SOLIBDIR)/pkgconfig@${PREFIX}/libdata/pkgconfig@' \
		-e '/$$(SO)/ s@$$(INSTALL) -m0755 @$$(BSD_INSTALL_LIB) @' \
		-e '/tools/ s@$$(INSTALL) -m0755 @$$(BSD_INSTALL_SCRIPT) @' \
		-e 's@$$(INSTALL) -m0755 @$$(BSD_INSTALL_PROGRAM) @' \
		-e '/$$(MANDIR)/ s@$$(INSTALL) -m0644 @$$(BSD_INSTALL_MAN) @' \
		-e 's@$$(INSTALL) -m0644 @$$(BSD_INSTALL_DATA) @' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>

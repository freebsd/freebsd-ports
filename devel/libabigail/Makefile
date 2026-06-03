PORTNAME=	libabigail
DISTVERSION=	2.9
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	ABI Generic Analysis and Instrumentation Library
WWW=		https://sourceware.org/libabigail/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libdw.so:devel/elfutils \
		libxxhash.so:devel/xxhash

USES=		compiler:c++11-lang gmake gnome libtool localbase pkgconfig \
		python tar:xz
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes

TEST_TARGET=	check

TESTING_UNSAFE=	some tests fail due to ? sorting issues in libc++ ?

.include <bsd.port.mk>

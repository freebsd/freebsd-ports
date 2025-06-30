PORTNAME=	libabigail
DISTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	ABI Generic Analysis and Instrumentation Library
WWW=		https://sourceware.org/libabigail/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libdw.so:devel/elfutils

USES=		compiler:c++11-lang gmake gnome libtool localbase pkgconfig \
		python
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx11=yes

.include <bsd.port.mk>

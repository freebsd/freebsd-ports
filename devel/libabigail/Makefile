PORTNAME=	libabigail
DISTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/${PORTNAME}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	ABI Generic Analysis and Instrumentation Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libdw.so:devel/elfutils

USES=		compiler:c++11-lang gmake libtool localbase pkgconfig python

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx11=yes

.include <bsd.port.mk>

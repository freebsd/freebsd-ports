# $FreeBSD$

PORTNAME=	systemc
DISTVERSION=	2.3.4
DISTVERSIONSUFFIX=	_pub_rev_20190614
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ classes and macros for describing complex hardware systems

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	configure: error: sorry...architecture not supported

USES=		gmake libtool
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	accellera-official

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unix-layout=yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>

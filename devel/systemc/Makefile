# $FreeBSD$

PORTNAME=	systemc
DISTVERSION=	2.3.3
CATEGORIES=	devel
MASTER_SITES=	https://accellera.org/images/downloads/standards/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ classes and macros for describing complex hardware systems

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	configure: error: sorry...architecture not supported

USES=		gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unix-layout=yes

INSTALL_TARGET=install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.5.12
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	ironbee
GH_COMMIT=	a85cb55

USES=		libtool pkgconfig pathfix iconv
USE_AUTOTOOLS=	libtoolize automake aclocal autoheader
USE_LDCONFIG=	yes

AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}

PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=		install-strip
CONFLICTS_INSTALL=	libhtp-suricata-*

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>

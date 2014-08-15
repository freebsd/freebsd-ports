# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.5.15
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ironbee
GH_COMMIT=	440da09

USES=		libtool pkgconfig pathfix iconv
USE_AUTOTOOLS=	libtoolize automake aclocal autoheader
USE_LDCONFIG=	yes

AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
MAKE_ARGS=	LIBS="-lz ${ICONV_LIB}"

PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=		install-strip
CONFLICTS_INSTALL=	libhtp-suricata-*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>

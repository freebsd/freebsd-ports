# $FreeBSD$

PORTNAME=	libhtp
PORTVERSION=	0.5.16
CATEGORIES=	devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Security-aware parser for the HTTP protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	OISF
GH_COMMIT=	4cb1b99

USES=		autoreconf iconv:translit libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG}
MAKE_ARGS=	LIBS="-lz ${ICONV_LIB}"

PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=		install-strip
CONFLICTS_INSTALL=	libhtp-suricata-*

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

regression-test: build
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>

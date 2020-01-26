# $FreeBSD$

PORTNAME=	fth
DISTVERSION=	1.4.1
CATEGORIES=	lang
MASTER_SITES=	SF/fth/fth/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Forth interpreter and extension library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bz2 ssl  # ssl is used only for the bignum interface BN_*
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	test

OPTIONS_DEFINE=		TECLA
OPTIONS_DEFAULT=	TECLA
TECLA_DESC=		Use tecla command-line editing

TECLA_CONFIGURE_WITH=	tecla
TECLA_LIB_DEPENDS=	libtecla.so:devel/libtecla

.include <bsd.port.mk>

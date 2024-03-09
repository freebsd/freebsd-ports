PORTNAME=	fth
DISTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/fth/fth/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Forth interpreter and extension library
WWW=		https://sourceforge.net/projects/fth/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bz2 ssl  # ssl is used only for the bignum interface BN_*
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-strip
TEST_TARGET=	test

OPTIONS_DEFINE=		TECLA
OPTIONS_DEFAULT=	TECLA
TECLA_DESC=		Use tecla command-line editing

TECLA_CONFIGURE_WITH=	tecla
TECLA_LIB_DEPENDS=	libtecla.so:devel/libtecla

.include <bsd.port.mk>

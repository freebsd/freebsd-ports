# $FreeBSD$

PORTNAME=	shtk
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/jmmv

MAINTAINER=	jmmv@freebsd.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts

LICENSE=	BSD

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-atf

MAKE_ARGS=      pkgconfigdir=${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=		TEST
OPTIONS_SUB=		yes
TEST_CONFIGURE_WITH=	atf

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	shtk
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/jmmv

MAINTAINER=	jmmv@freebsd.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts

LICENSE=	BSD

GNU_CONFIGURE=	yes

MAKE_ARGS=      pkgconfigdir=${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=		TEST
OPTIONS_SUB=		yes
TEST_CONFIGURE_WITH=	atf
TEST_BUILD_DEPENDS=	${PREFIX}/bin/atf-sh:${PORTSDIR}/devel/atf
TEST_RUN_DEPENDS=	atf>=0.20:${PORTSDIR}/devel/atf

.include <bsd.port.mk>

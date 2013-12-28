# $FreeBSD$

PORTNAME=	shtk
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	jmmv@freebsd.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts

LICENSE=	BSD

FETCH_ARGS=     -Fpr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-atf

MAKE_ARGS=      pkgconfigdir=${PREFIX}/libdata/pkgconfig

MAN1=		shtk.1

.include <bsd.port.mk>

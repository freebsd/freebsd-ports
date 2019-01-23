# $FreeBSD$

PORTNAME=	tradcpp
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	https://ftp.NetBSD.org/pub/NetBSD/misc/dholland/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traditional (K&R-style) C preprocessor

LICENSE=	BSD2CLAUSE

USES=		uidfix

MAKE_ARGS=	BINDIR=${PREFIX}/bin MANDIR=${MANPREFIX}/man/man

PLIST_FILES=	bin/tradcpp \
		man/man1/tradcpp.1.gz

.include <bsd.port.mk>

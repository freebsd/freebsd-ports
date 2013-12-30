# $FreeBSD$

PORTNAME=	tradcpp
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/dholland/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Traditional (K&R-style) C preprocessor

LICENSE=	BSD2CLAUSE

USES=		uidfix

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

MAKE_ARGS=	BINDIR=${PREFIX}/bin MANDIR=${MANPREFIX}/man/man

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	tradcpp
PORTVERSION=	0.5.2
CATEGORIES=	devel
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/dholland/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traditional (K&R-style) C preprocessor

LICENSE=	BSD2CLAUSE

MAKE_ARGS=	BINDIR=${PREFIX}/bin MANDIR=${MANPREFIX}/man/man
USES=		uidfix

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>

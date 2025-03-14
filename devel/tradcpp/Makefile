PORTNAME=	tradcpp
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	https://cdn.NetBSD.org/pub/NetBSD/misc/dholland/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traditional (K&R-style) C preprocessor
WWW=		https://www.NetBSD.org/~dholland/tradcpp/

LICENSE=	BSD2CLAUSE

USES=		uidfix

MAKE_ARGS=	BINDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/share/man/man

PLIST_FILES=	bin/tradcpp \
		share/man/man1/tradcpp.1.gz

.include <bsd.port.mk>

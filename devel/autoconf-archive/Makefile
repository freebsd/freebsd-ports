PORTNAME=	autoconf-archive
PORTVERSION=	0.${DISTDATE:C/-/./g}
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME}-${DISTDATE}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Set of useful GNU Autoconf macros

USES=		makeinfo tar:xz
DISTDATE=	2019.01.06
GNU_CONFIGURE=	yes
INFO=		${PORTNAME}

NO_ARCH=	yes

PLIST_SUB=	MACRODIR=share/aclocal

.include <bsd.port.mk>

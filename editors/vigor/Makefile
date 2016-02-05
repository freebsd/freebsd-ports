# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	vigor
PORTVERSION=	0.016
PORTREVISION=	4
CATEGORIES=	editors tcl tk
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vi clone inspired by the userfriendly comic strip

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

WRKSRC=		${WRKDIR}/${DISTNAME}/build

USES=		ncurses tk
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--exec-prefix=${STAGEDIR}${PREFIX}

CPPFLAGS+=	-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's|tcl80|tcl${TCL_SHLIB_VER}|; \
		s|-lcurses|-lncurses|; \
		s|tk80|tk${TK_SHLIB_VER}|; \
		s|^grantpt|XXXgrantpt|;' \
			${WRKSRC}/configure

.include <bsd.port.mk>

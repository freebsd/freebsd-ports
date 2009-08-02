# New ports collection makefile for:   vigor
# Date created:        17 Jan 2000
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	vigor
PORTVERSION=	0.016
PORTREVISION=	4
CATEGORIES=	editors tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A vi clone inspired by the userfriendly comic strip

USE_TCL=	yes
USE_TCL_BUILD=	yes
USE_TK=		yes
USE_TK_BUILD=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--program-transform-name="s,0,1,"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${DISTNAME}/build
CFLAGS+=	-I${LOCALBASE}/include/tcl${TCL_VER} -I${LOCALBASE}/include/tk${TK_VER}

post-patch:
	${REINPLACE_CMD} -e 's|tcl80|tcl${TCL_VER:S/.//} -L${LOCALBASE}/lib|; \
		s|tk80|tk${TK_VER:S/.//}|; \
		s|^grantpt|XXXgrantpt|;' \
			${WRKSRC}/configure

.include <bsd.port.mk>

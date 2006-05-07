# New ports collection makefile for:   vigor
# Date created:        17 Jan 2000
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	vigor
PORTVERSION=	0.016
CATEGORIES=	editors tk82 tcl82
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A vi clone inspired by the userfriendly comic strip

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		tcl82.1:${PORTSDIR}/lang/tcl82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--program-transform-name="s,0,1,"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=	${WRKDIR}/${DISTNAME}/build
CFLAGS+= 	-I${LOCALBASE}/include/tcl8.2 -I${LOCALBASE}/include/tk8.2

# Uglyness. So is "-ltcl -ltk -ltcl", so I don't feel bad.
post-patch:
	${REINPLACE_CMD} \
		-e 's,-ltcl,-ltcl82 -L${LOCALBASE}/lib,g' \
		-e 's,-ltk,-ltk82,g' \
		-e 's,^grantpt,XXXgrantpt,g' \
		${WRKSRC}/configure

.include <bsd.port.mk>

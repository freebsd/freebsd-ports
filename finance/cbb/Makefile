# New ports collection Makefile for:	cbb
# Date created:			24 September, 1998
# Whom:				kline
#
# $FreeBSD$
#

PORTNAME=	cbb
DISTVERSION=	0.9.5b
CATEGORIES=	finance deskutils
MASTER_SITES=	http://download.gna.org/cbb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kline@thought.org
COMMENT=	Checkbook balancing tool

USE_TK=		yes

NO_BUILD=	yes
USES=		perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-perl=${PERL} \
		--with-wish=${WISH}
WRKSRC=		${WRKDIR}/${PKGNAME:R}
PLIST_SUB+=	VERSION=${PORTVERSION:R:R}

post-patch:
	${REINPLACE_CMD}  -e 's|.aboutwin.frame.a.l6 ||' \
	    ${WRKSRC}/tcl/help.tcl
	${REINPLACE_CMD}  -e 's|%4Y%02m%02d|%Y%m%d|' \
	    ${WRKSRC}/tcl/main.tcl

.include <bsd.port.mk>

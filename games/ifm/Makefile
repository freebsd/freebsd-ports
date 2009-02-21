# New ports collection makefile for:	ifm
# Date created:				Mon Oct 12 12:32:07 EDT 1998
# Whom:					Dave Chapeskie <dchapes@ddm.on.ca>
#
# $FreeBSD$
#

PORTNAME=	ifm
PORTVERSION=	5.4
CATEGORIES=	games tk
MASTER_SITES=	http://www.ifarchive.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	if-archive/mapping-tools

MAINTAINER=	akosela@andykosela.com
COMMENT=	Interactive Fiction mapper and walkthrough generator

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_GZIP=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	WISH=${LOCALBASE}/bin/wish8.4

MAN1=		ifm.1

post-patch:
	@${REINPLACE_CMD} -e 's/lib doc man/lib man/g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/docdir/d' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

# New ports collection makefile for:	yudit
# Version required:	1.2
# Date created:		October 3, 1998
# Whom:			rch@richard.eu.org
#
# $Id: Makefile,v 1.2 1998/12/12 21:03:34 jseger Exp $
#

DISTNAME=	yudit-1.2
CATEGORIES=	editors converters print
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= apps/editors/X

MAINTAINER=	rch@WriteMe.Com

LIB_DEPENDS=	ttf.3:${PORTSDIR}/print/freetype

CONFIGURE_ENV=	LC_ALL=C
GNU_CONFIGURE=	YES
MAKE_ENV=	LC_ALL=C
MAN1=		yudit.1 makeumap.1 stripumap.1 uniconv.1 uniprint.1
USE_GMAKE=	YES

pre-patch:
	${CP} ${FILESDIR}/*map ${WRKSRC}/data

post-install:
	cd ${PREFIX}/bin/ && strip yudit stripumap uniconv uniprint

.include <bsd.port.mk>

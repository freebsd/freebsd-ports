# New ports collection makefile for:	jpeg
# Version required:	5b
# Date created:		6 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.7 1995/04/16 02:14:19 asami Exp $
#

DISTNAME=	jpegsrc.v5b
PKGNAME=	jpeg-5b
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.uu.net/graphics/jpeg/ \
		ftp://ftp.netcom.com/pub/tgl/uunet/

WRKSRC=		${WRKDIR}/jpeg-5b
GNU_CONFIGURE=	yes

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>

# New ports collection makefile for:	jpeg
# Version required:     6
# Date created:		6 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.9 1995/10/02 14:04:54 ache Exp $
#

DISTNAME=       jpegsrc.v6
PKGNAME=        jpeg-6
CATEGORIES+=	graphics
MASTER_SITES=	ftp://ftp.uu.net/graphics/jpeg/ \
		ftp://ftp.netcom.com/pub/tg/tgl/uunet/

WRKSRC=         ${WRKDIR}/jpeg-6
GNU_CONFIGURE=	yes
INSTALL_TARGET= install install-lib

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>

# New ports collection makefile for:	jpeg
# Version required:     6a
# Date created:		6 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.13 1996/11/18 14:00:09 asami Exp $
#

DISTNAME=       jpegsrc.v6a
PKGNAME=        jpeg-6a
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/jpeg/

WRKSRC=         ${WRKDIR}/jpeg-6a
GNU_CONFIGURE=	yes
INSTALL_TARGET= install install-lib
MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

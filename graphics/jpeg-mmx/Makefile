# New ports collection makefile for:	jpeg
# Version required:     6b
# Date created:		6 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.15 1998/04/15 21:32:49 jseger Exp $
#

DISTNAME=       jpegsrc.v6b
PKGNAME=        jpeg-6b
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/jpeg/

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=         ${WRKDIR}/jpeg-6b
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
MAN1=		cjpeg.1 djpeg.1 jpegtran.1 rdjpgcom.1 wrjpgcom.1

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

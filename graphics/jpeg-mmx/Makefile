# New ports collection makefile for:	jpeg
# Version required:     6b
# Date created:		6 November 1994
# Whom:			smace
#
# $FreeBSD$
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
USE_LIBTOOL=	yes

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/jpeg
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/jpeg
.endif

.include <bsd.port.mk>

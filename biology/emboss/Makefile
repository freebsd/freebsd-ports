# New ports collection makefile for:	emboss
# Date created:		31 July 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	emboss
PORTVERSION=	1.5.0
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.uk.embnet.org/pub/EMBOSS/ \
		ftp://ftp.no.embnet.org/pub/EMBOSS/
DISTNAME=	EMBOSS-${PORTVERSION}

MAINTAINER=	johann@egenetics.com

LIB_DEPENDS=	gd.1:${PORTSDIR}/graphics/gd \
		png.4:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_XLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/gd" \
		LIBS="-L${LOCALBASE}/lib"

DOC_DIRS= doc/manuals doc/tutorials doc/programs/text doc/programs/html

post-patch:
.for DIR in ${DOC_DIRS}
	@ ${PERL} -pi.orig -e \
	  "s#share/\\$$\(PACKAGE\)/doc#share/doc/\\$$\(PACKAGE\)#" \
	  ${WRKSRC}/${DIR}/Makefile.in
.endfor

post-install:
	@ ${INSTALL_DATA} ${WRKSRC}/emboss/acd/emboss.default \
	  ${PREFIX}/etc/emboss.default.sample
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>

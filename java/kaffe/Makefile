# New ports collection makefile for:    kaffe
# Version required:     0.9.1
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $Id: Makefile,v 1.25 1997/06/26 15:50:06 max Exp $
#

DISTNAME=	kaffe-0.9.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/ \
		ftp://alterego.stack.nl/pub/kaffe/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.tgz kaffe-0.9.1-package-biss-net.com.tgz \
		kaffe-0.9.1-package-javasoft.com.tgz

MAINTAINER=	xaa@stack.nl

GNU_CONFIGURE=	yes
MAN1=		kaffe.1

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

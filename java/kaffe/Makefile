# New ports collection makefile for:    kaffe
# Version required:     0.8.4
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $Id: Makefile,v 1.24 1997/06/26 06:50:59 tg Exp $
#

DISTNAME=	kaffe-0.8.4
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.tgz kaffe-0.8.4-package-biss-net.com.tgz \
		kaffe-0.8.4-package-javasoft.com.tgz

MAINTAINER=	xaa@stack.nl

GNU_CONFIGURE=	yes
MAN1=		kaffe.1

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>

# New ports collection makefile for:    kaffe
# Version required:     0.3
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $Id: Makefile,v 1.1.1.1 1996/03/07 03:53:56 asami Exp $
#

DISTNAME=	kaffe-0.3
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.sarc.city.ac.uk/pub/kaffe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tim@sarc.city.ac.uk

GNU_CONFIGURE=	yes

do-configure:
		@(cd ${WRKSRC}; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	cp ${WRKSRC}/sun/COPYRIGHT ${PREFIX}/share/kaffe
	cp ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>

# New ports collection makefile for:	xapian-core
# Date created:				5 November 2005
# Whom:					J.F. Dockes
#
# $FreeBSD$
#

PORTNAME=	xapian-core
PORTVERSION=	0.9.2
CATEGORIES=	databases
MASTER_SITES=	http://www.oligarchy.co.uk/xapian/${PORTVERSION}/

MAINTAINER=	jean-francois.dockes@wanadoo.fr
COMMENT=	A probabilistic text search database engine

USE_AUTOTOOLS=	libtool:15
INSTALLS_SHLIB=	yes

post-install:
.for file in delve quest copydatabase
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${file} ${PREFIX}/bin/xapian-${file}
.endfor

.include <bsd.port.mk>

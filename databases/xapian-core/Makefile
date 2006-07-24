# New ports collection makefile for:	xapian-core
# Date created:				5 November 2005
# Whom:					J.F. Dockes
#
# $FreeBSD$
#

PORTNAME=	xapian-core
PORTVERSION=	0.9.6
PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	http://www.oligarchy.co.uk/xapian/${PORTVERSION}/

MAINTAINER=	jean-francois.dockes@wanadoo.fr
COMMENT=	A probabilistic text search database engine

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=		xapian-config.1 quartzcheck.1 quartzcompact.1 quartzdump.1 \
		xapian-compact.1 xapian-tcpsrv.1

PORTDOCS=	*

post-install:
.for file in delve quest copydatabase
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${file} ${PREFIX}/bin/xapian-${file}
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:	xapian-core
# Date created:				5 November 2005
# Whom:					J.F. Dockes
#
# $FreeBSD$
#

PORTNAME=	xapian-core
PORTVERSION=	1.0.17
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/

MAINTAINER=	jean-francois.dockes@wanadoo.fr
COMMENT=	A probabilistic text search database engine

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		quartzcheck.1 quartzcompact.1 quartzdump.1 \
		xapian-check.1 xapian-compact.1 xapian-config.1 \
		xapian-progsrv.1 xapian-tcpsrv.1 xapian-inspect.1

post-install:
.for file in delve quest copydatabase
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/${file} ${PREFIX}/bin/xapian-${file}
.endfor
.ifdef(NOPORTDOCS)
	${RM} -rf ${DOCSDIR}
.endif

.include <bsd.port.mk>

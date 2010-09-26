# New ports collection makefile for:	xapian-core
# Date created:				5 November 2005
# Whom:					J.F. Dockes
#
# $FreeBSD$
#

PORTNAME=	xapian-core
PORTVERSION=	1.2.3
CATEGORIES=	databases
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/

MAINTAINER=	jf@dockes.org
COMMENT=	A probabilistic text search database engine

LIB_DEPENDS=	uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

USE_LDCONFIG=	yes

MAN1=		xapian-check.1 xapian-chert-update.1 xapian-compact.1 \
		xapian-config.1 xapian-inspect.1 xapian-metadata.1 \
		xapian-progsrv.1 xapian-replicate-server.1 xapian-tcpsrv.1 \
		xapian-replicate.1

post-install:
.ifdef(NOPORTDOCS)
	${RM} -rf ${DOCSDIR}
.endif

.include <bsd.port.mk>

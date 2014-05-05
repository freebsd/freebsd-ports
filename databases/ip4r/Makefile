# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ip4r
PORTVERSION=	2.0
CATEGORIES=	databases net
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3380/

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	IP address and IP range index types for PostgreSQL

USES=		gmake pgsql

MAKE_ARGS=	USE_PGXS=1

# In order to make this port PREFIX-safe, we override the install target
# and install the three files manually
do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/postgresql
	@${INSTALL_LIB} -m ${BINMODE} ${WRKSRC}/ip4r.so ${STAGEDIR}${PREFIX}/lib/postgresql
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/postgresql/contrib
	@${INSTALL_DATA} ${WRKSRC}/ip4r.sql \
		${STAGEDIR}${PREFIX}/share/postgresql/contrib
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/postgresql/contrib
	@${INSTALL_DATA} ${WRKSRC}/README.ip4r \
		${STAGEDIR}${PREFIX}/share/doc/postgresql/contrib

.include <bsd.port.mk>

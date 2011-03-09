# New ports collection makefile for:	ip4r
# Date created:				15th December 2005
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ip4r
PORTVERSION=	1.05
CATEGORIES=	databases net
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2607/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IPv4 and IPv4 range index type for PostgreSQL

USE_PGSQL=	YES
USE_GMAKE=	YES

# 74 is not strictly true, but requires extracting the appropriate
# postgresql-contrib tarball, and associated heavy lifting.
# In order to keep this port simple, we assume >= 8.0
IGNORE_WITH_PGSQL=	73 74

MAKE_ARGS=	USE_PGXS=1

# In order to make this port PREFIX-safe, we override the install target
# and install the three files manually
do-install:
	@${INSTALL} -m ${BINMODE} ${WRKSRC}/ip4r.so ${PREFIX}/lib/postgresql
	@${MKDIR} ${PREFIX}/share/postgresql/contrib
	@${INSTALL_DATA} ${WRKSRC}/ip4r.sql \
		${PREFIX}/share/postgresql/contrib
	@${MKDIR} ${PREFIX}/share/doc/postgresql/contrib
	@${INSTALL_DATA} ${WRKSRC}/README.ip4r \
		${PREFIX}/share/doc/postgresql/contrib

.include <bsd.port.mk>

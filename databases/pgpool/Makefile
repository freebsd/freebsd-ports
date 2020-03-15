# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	pgpool
PORTVERSION=	3.4.26
CATEGORIES=	databases
MASTER_SITES=	http://www.pgpool.net/mediawiki/images/
DISTNAME=	${PORTNAME}-II-${PORTVERSION}

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Connection pool server for PostgreSQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Reached EOL at 2019-10-31, please use pgpool-II-35 or higher
EXPIRATION_DATE=	2020-03-31

USES=		gmake libtool pgsql:9.3+

PORTSCOUT=	limit:^3.4.[0-9]*

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}-II

USE_RC_SUBR=	pgpool
CONFLICTS=	pgpool-II-*

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS SSL
OPTIONS_DEFAULT=	SSL

SSL_CONFIGURE_WITH=	openssl
SSL_USES=		ssl

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/pgpool
	${INSTALL_LIB} ${WRKSRC}/src/libs/pcp/.libs/libpcp.so.0.0.0 ${STAGEDIR}${PREFIX}/lib

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR} "-not -name Makefile.\*"
.for f in AUTHORS ChangeLog NEWS TODO
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

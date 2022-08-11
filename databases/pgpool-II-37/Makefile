PORTNAME=	pgpool-II
PORTVERSION=	3.7.24
CATEGORIES=	databases
MASTER_SITES=	http://www.pgpool.net/mediawiki/images/
PKGNAMESUFFIX=	37

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Connection pool server for PostgreSQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream EOL reaches on 2022-11 use pgpool-II-43
EXPIRATION_DATE=	2022-12-30

USES=		gmake libtool pgsql:9.6+
USE_LDCONFIG=	yes
USE_RC_SUBR=	pgpool

GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	pgpool-II-[0-9][0-9] pgpool-II[0-9][0-9] # etc/pcp.conf.sample

PORTSCOUT=	limit:^3.7.[0-9]*

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS SSL
OPTIONS_DEFAULT=	SSL

SSL_USES=		ssl
SSL_CONFIGURE_WITH=	openssl

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/pgpool
	${INSTALL_LIB} ${WRKSRC}/src/libs/pcp/.libs/libpcp.so.1.0.0 ${STAGEDIR}${PREFIX}/lib

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${DOCSDIR} "-not -name Makefile.\*"
.for f in AUTHORS ChangeLog NEWS TODO
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

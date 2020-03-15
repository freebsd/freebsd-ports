# $FreeBSD$

PORTNAME=	pgpool-II
PORTVERSION=	4.0.8
CATEGORIES=	databases
MASTER_SITES=	http://www.pgpool.net/mediawiki/images/
PKGNAMESUFFIX=	40

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Connection pool server for PostgreSQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^4.0.[0-9]*

USES=		gmake libtool pgsql:9.6+
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_RC_SUBR=	pgpool
CONFLICTS=	pgpool-II-[0-9]*

PORTDOCS=	*

PAM_DESC=	Build with PAM support
SSL_DESC=	Build with OpenSSL support
MEMCACHED_DESC =	Use memcached for in memory query cache

OPTIONS_DEFINE=	DOCS SSL PAM MEMCACHED
OPTIONS_DEFAULT=	SSL

MEMCACHED_CONFIGURE_ON=	--with-memcached=${LOCALBASE}/include
MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached

PAM_CONFIGURE_ON=	--with-pam

SSL_CONFIGURE_WITH=	openssl
SSL_USES=		ssl

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

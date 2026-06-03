PORTNAME=	proxysql
PORTVERSION=	3.0.8
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	zi@FreeBSD.org
COMMENT=	High performance, high availability, protocol-aware proxy for MySQL
WWW=		https://www.proxysql.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		cmake:devel/cmake-core \
		ggrep:textproc/gnugrep \
		libgcrypt>0:security/libgcrypt \
		libevent>0:devel/libevent \
		gnutls>0:security/gnutls
LIB_DEPENDS=	libuuid.so:misc/libuuid
RUN_DEPENDS=	libgcrypt>0:security/libgcrypt \
		gnutls>0:security/gnutls

USES=		autoreconf:build bison:build compiler:c++11-lang gmake \
		libtool perl5 pkgconfig python:build ssl
USE_CSTD=	gnu11
USE_PERL5=	build
USE_GCC=	yes
MAKE_ENV=	GIT_VERSION_BASE="${PORTVERSION}" SOURCE_DATE_EPOCH="$$(date +%s)"
USE_GITHUB=	yes
ALL_TARGET=	build_deps default
LDFLAGS+=	-L${LOCALBASE}/lib
BINARY_ALIAS=	python3=${PYTHON_CMD}
USE_RC_SUBR=	${PORTNAME}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

GH_ACCOUNT=	sysown

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 1400000 && ${SSL_DEFAULT} == "base")
IGNORE=		requires OpenSSL 3.x or greater
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${ETCDIR}/,g' ${WRKSRC}/lib/ProxySQL_GloVars.cpp
	@${REINPLACE_CMD} \
		-e 's,/var/lib,/var/db,g' \
		-e '7s/^/errorlog="\/var\/log\/proxysql\/proxysql-error.log"\n\n/g' \
		-e '7s/^/pidfile="\/var\/run\/${PORTNAME}\/${PORTNAME}.pid"\n/g' \
		${WRKSRC}/src/proxysql.cfg
	@${REINPLACE_CMD} \
		-e '/^GIT_VERSION_BASE := /d' \
		-e 's,grep -P,g&,' \
		-e '/ export C/d' \
		-e 's,PROXYSQLCLICKHOUSE=1 ,,g' \
		-e '/cd curl/s,$${MAKE},${GMAKE},' \
		-e '/cd libmicrohttpd/s,$${MAKE},${GMAKE},' \
		-e '/cd lz4/s,$${MAKE},${GMAKE},' \
		-e '/cd libhttpserver.*MAKE/s,CC,MAKE=${GMAKE} CC,' \
		-e '/cd libhttpserver/s,$${MAKE},${GMAKE},' \
		-e '/get_result_from_pgconn/s,-p0,-p0 -l,' \
		-e 's,without-readline,without-readline --without-icu,g' \
		-e 's,--enable-fastopen=false ,--enable-fastopen=false --enable-shared=no ,g' \
		${WRKSRC}/Makefile ${WRKSRC}/deps/Makefile
	@${REINPLACE_CMD} -e 's,grep -oP,ggrep -oP,g' ${WRKSRC}/common_mk/*.mk
	@${REINPLACE_CMD} -e 's,ENABLE_EPOLL := -DENABLE_EPOLL,ENABLE_EPOLL :=,g' \
		${WRKSRC}/lib/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/proxysql ${STAGEDIR}${LOCALBASE}/sbin

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/db/${PORTNAME} \
		${STAGEDIR}/var/run/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}/var/log/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/proxysql.conf-newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/proxysql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/src/proxysql.cfg \
		${STAGEDIR}${ETCDIR}/proxysql.cfg.sample

.include <bsd.port.post.mk>

PORTNAME=	proxysql
PORTVERSION=	2.6.4
CATEGORIES=	databases

MAINTAINER=	zi@FreeBSD.org
COMMENT=	High performance, high availability, protocol-aware proxy for MySQL
WWW=		https://www.proxysql.com/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	configure: error: Unsupported pointer size: 0

BUILD_DEPENDS=	aclocal:devel/automake \
		autoreconf:devel/autoconf \
		bash:shells/bash \
		cmake:devel/cmake-core \
		${LOCALBASE}/bin/grep:textproc/gnugrep \
		libgcrypt>0:security/libgcrypt \
		libtoolize:devel/libtool \
		e2fsprogs-libuuid>0:misc/e2fsprogs-libuuid \
		gnutls>0:security/gnutls
RUN_DEPENDS=	libgcrypt>0:security/libgcrypt \
		e2fsprogs-libuuid>0:misc/e2fsprogs-libuuid \
		gnutls>0:security/gnutls

USES=		compiler:c++11-lang gmake libtool perl5 python:build shebangfix
USE_PERL5=	build
USE_GCC=	yes
MAKE_ENV=	GIT_VERSION=${PORTVERSION}
USE_GITHUB=	yes
ALL_TARGET=	build_deps default
SHEBANG_FILES=	deps/libssl/verify-bio_st-match.sh
LDFLAGS+=	-L${LOCALBASE}/lib
BINARY_ALIAS=	python3=${PYTHON_CMD}
USE_RC_SUBR=	${PORTNAME}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

GH_ACCOUNT=	sysown

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${ETCDIR}/,g' ${WRKSRC}/lib/ProxySQL_GloVars.cpp
	@${REINPLACE_CMD} \
		-e 's|strftime(__buffer, 25, "%Y-%m-%d %H:%M:%S", __tm_info);|snprintf(__buffer, 3, "%s", "");|g' \
		-e 's,"%s \[,"%s\[,g' \
		-e '/__timer/d' \
		-e '/__tm_info/d' \
		${WRKSRC}/include/proxysql_debug.h
	@${REINPLACE_CMD} \
		-e 's,/var/lib,/var/db,g' \
		-e '7s/^/errorlog="\/var\/log\/proxysql\/proxysql-error.log"\n\n/g' \
		-e '7s/^/pid="\/var\/run\/${PORTNAME}\/${PORTNAME}.pid"\n/g' \
		${WRKSRC}/src/proxysql.cfg
	@${REINPLACE_CMD} \
		-e 's,grep,${LOCALBASE}/bin/grep,g' \
		-e 's,ln -fsT,ln -fs,' \
		-e 's,PROXYSQLCLICKHOUSE=1 ,,g' \
		-e 's,--enable-fastopen=false ,--enable-fastopen=false --enable-shared=no ,g' \
		${WRKSRC}/Makefile ${WRKSRC}/deps/Makefile \
		${WRKSRC}/lib/Makefile ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/proxysql ${STAGEDIR}${LOCALBASE}/sbin

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/db/${PORTNAME} \
		${STAGEDIR}/var/run/${PORTNAME} \
		${STAGEDIR}${LOCALBASE}/etc/syslog.d \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d \
		${STAGEDIR}/var/log/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf \
		${STAGEDIR}${LOCALBASE}/etc/syslog.d
	${INSTALL_DATA} ${FILESDIR}/proxysql.conf-newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/proxysql.conf.sample
	${INSTALL_DATA} ${WRKSRC}/src/proxysql.cfg \
		${STAGEDIR}${ETCDIR}/proxysql.cfg.sample

.include <bsd.port.mk>

# Created by: ijliao
# $FreeBSD$

PORTNAME=	dbtool
PORTVERSION=	1.9.1
CATEGORIES=	databases
MASTER_SITES=	http://www.daemon.de/idisk/Apps/dbtool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Store and retrieve data in a key/value format in a hash database

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USES=		gmake shebangfix
SHEBANG_FILES=	samples/account-db/accdb
bash_OLD_CMD=	/bin/sh
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTEXAMPLES=	*
PLIST_FILES=	bin/dbtool man/man1/dbtool.1.gz

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	BDB GDBM
OPTIONS_DEFAULT=	GDBM

BACKEND_DESC=		Database backend
BDB_USE=		bdb=yes
BDB_CONFIGURE_ON=	--with-berkeley \
			--with-bdb-include-dir=${BDB_INCLUDE_DIR} \
			--with-bdb-lib-dir=${BDB_LIB_DIR}
EXAMPLES_RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
GDBM_LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm
GDBM_CONFIGURE_ON=	--with-gdbm \
			--with-gdbm-dir=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e \
		'/try_libs=/s|"-ldb_cxx.*"|"-ldb_cxx"| ; \
		 /try_headers=/s|"db.*"|"db_cxx.h"|' ${WRKSRC}/configure

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

# Created by: Tomoyuki Sakurai <tomoyukis@smer.jp.reallyenglish.com>
# $FreeBSD$

PORTNAME=	pgmecab
PORTVERSION=	1.1
CATEGORIES=	databases
MASTER_SITES=	http://dist.reallyenglish.com/pgmecab/

MAINTAINER=	tomoyukis@smer.jp.reallyenglish.com
COMMENT=	Mecab for Postgresql

LIB_DEPENDS=	mecab:${PORTSDIR}/japanese/mecab
RUN_DEPENDS=	${LOCALBASE}/lib/mecab/dic/ipadic/matrix.bin:${PORTSDIR}/japanese/mecab-ipadic

USE_BZIP2=	Yes
USE_PGSQL=	Yes
# XXX dirty hack to make it compile without patch
# for 8.3 or later, you need this patch
# http://bugs.gentoo.org/239594
WANT_PGSQL_VER=	82
USE_GMAKE=	Yes

# docdir=${DOCSDIR} USE_PGXS=1
MAKE_ARGS+=	PG_CONFIG=${LOCALBASE}/bin/pg_config USE_PGXS=1

# In order to make this port PREFIX-safe, we override the install target
# and install the three files manually
do-install:
	${MKDIR} ${PREFIX}/lib/postgresql
	${INSTALL} -m ${BINMODE} ${WRKSRC}/libpgmecab.so ${PREFIX}/lib/postgresql/pgmecab.so
	${MKDIR} ${PREFIX}/share/postgresql/contrib
	${INSTALL_DATA} ${WRKSRC}/pgmecab.sql \
		${PREFIX}/share/postgresql/contrib
	${MKDIR} ${PREFIX}/share/doc/postgresql/contrib
	${INSTALL_DATA} ${WRKSRC}/README.pgmecab \
		${PREFIX}/share/doc/postgresql/contrib

.include <bsd.port.mk>

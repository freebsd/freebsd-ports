# New ports collection makefile for: pgbash
# Date created:		6 July 2003
# Whom:			Sascha Holzleiter <sascha@root-login.org>
#
# $FreeBSD$
#

PORTNAME=	pgbash
PORTVERSION=	7.3
CATEGORIES=	databases
MASTER_SITES=	http://www.psn.co.jp/PostgreSQL/pgbash/:pgsource \
		${MASTER_SITE_GNU:S/$/:bashsrc/}
MASTER_SITE_SUBDIR=	bash/:bashsrc
DISTFILES=	pgbash-7.3.tar.gz:pgsource \
	        bash-2.05a.tar.gz:bashsrc
EXTRACT_ONLY=	pgbash-7.3.tar.gz

MAINTAINER=	sascha@root-login.org
COMMENT=	SQL Bash Shell for PostgreSQL

LIB_DEPENDS=	pq.3:${PORTSDIR}/databases/postgresql-client

WRKSRC=		${WRKDIR}/pgbash-7.3/src/bash-2.05a

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS=	--pginc-prefix=${LOCALBASE}/include --pglib-prefix=${LOCALBASE}/lib

post-extract:
	@${ECHO_MSG} ">>> extracting bash"
	@${TAR} -C ${WRKDIR}/pgbash-7.3/src -xzf ${DISTDIR}/bash-2.05a.tar.gz

pre-configure:
	@${REINPLACE_CMD} -e 's|/etc/pgbashrc|${PREFIX}/etc/pgbashrc|g' \
	${WRKDIR}/pgbash-7.3/src/bash-2.05a-patch/shell.c.patch
.for i in Makefile.in.patch builtins-Makefile.in.patch \
	builtins-declare.def.patch builtins-mkbuilrins.c.patch \
	builtins-set.def.patch builtins-setattr.def.patch configure.in.patch \
	configure.patch parse.y.patch shell.c.patch variables.c.patch
	@${ECHO_MSG} ">>> applying pg patches"
	@${PATCH} -d ${WRKSRC} -p1 < ${WRKDIR}/pgbash-7.3/src/bash-2.05a-patch/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgbash ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/pgbash-7.3/rc/pgbashrc ${PREFIX}/etc/pgbashrc-dist

.include <bsd.port.mk>

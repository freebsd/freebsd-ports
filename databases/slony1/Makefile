# New ports collection makefile for:	slony1
# Date created:		20 Jun 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	slony1
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://developer.postgresql.org/~wieck/slony1/download/

MAINTAINER=	vivek@khera.org
COMMENT=	PostgreSQL master to multiple slaves replication system

PGSQL_PORT=	${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
BUILD_DEPENDS=	${NONEXISTENT}:${PGSQL_PORT}:configure
.if ! defined(NOPORTDOCS)
BUILD_DEPENDS+=	${LOCALBASE}/bin/pnmtops:${PORTSDIR}/graphics/netpbm \
		${LOCALBASE}/bin/djpeg:${PORTSDIR}/graphics/jpeg \
		${LOCALBASE}/bin/ps2pdf:${PORTSDIR}/print/ghostscript-gnu
.else
EXTRA_PATCHES=	${FILESDIR}/extra-GNUmakefile.in
.endif
RUN_DEPENDS=	${LOCALBASE}/bin/postmaster:${PGSQL_PORT}

GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
PGSQL_SRC=	`cd ${PGSQL_PORT}; make -V WRKSRC`
CONFIGURE_ARGS=	--with-pgsourcetree=${PGSQL_SRC}

PLIST_FILES=	bin/slon bin/slonik bin/slony_setup.pl \
		lib/postgresql/slony1_funcs.so lib/postgresql/xxid.so \
		share/postgresql/slony1_base.sql \
		share/postgresql/slony1_funcs.sql \
		share/postgresql/slony1_base.v73.sql \
		share/postgresql/slony1_base.v74.sql \
		share/postgresql/slony1_funcs.v73.sql \
		share/postgresql/slony1_funcs.v74.sql \
		share/postgresql/xxid.v73.sql \
		share/postgresql/xxid.v74.sql
PORTDOCS=	*.pdf howto COPYRIGHT README slonik_commands.html

DEFAULT_PGSQL_VER?=74

.include <bsd.port.pre.mk>
# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -n 's/postmaster.*PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

pre-configure:
	cd ${PGSQL_SRC}/src/interfaces/libpq && ${GMAKE} all
	cd ${PGSQL_SRC}/src/port && ${GMAKE} all

do-install:
	cd ${WRKSRC} && ${GMAKE} install
	${INSTALL_SCRIPT} ${WRKSRC}/tools/slony_setup.pl ${PREFIX}/bin
.if ! defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/concept/Slony-I-concept.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/implementation/Slony-I-implementation.pdf ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/howto
	${INSTALL_DATA} ${WRKSRC}/doc/howto/*.txt ${DOCSDIR}/howto
	${INSTALL_DATA} ${WRKSRC}/doc/howto/slonik_commands.html ${DOCSDIR}
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

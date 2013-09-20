# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	super-smack
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	benchmarks databases
MASTER_SITES=	http://vegan.net/tony/supersmack/

MAINTAINER=	gslin@gslin.org
COMMENT=	Benchmarking, stress testing, and load generation tool for Databases

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-smacks-dir=${DATADIR}
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	README TUTORIAL

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

PGSQL_DESC=	Enable PostgreSQL support
MYSQL_DESC=	Enable MySQL support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql \
		--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALBASE}/lib/mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql \
		--with-pgsql-include=${LOCALBASE}/include \
		--with-pgsql-lib=${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

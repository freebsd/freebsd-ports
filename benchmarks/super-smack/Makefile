# New ports collection makefile for:	super-smack
# Date created:		2005-12-10
# Whom:			Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	super-smack
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	benchmarks databases
MASTER_SITES=	http://vegan.net/tony/supersmack/

MAINTAINER=	gslin@gslin.org
COMMENT=	A benchmarking, stress testing, and load generation tool for Databases

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-smacks-dir=${DATADIR}

PORTDOCS=	README TUTORIAL

OPTIONS=	MYSQL "Enable MySQL support" on \
		POSTGRESQL "Enable PostgreSQL support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql \
		--with-mysql-include=${LOCALBASE}/include/mysql \
		--with-mysql-lib=${LOCALBASE}/lib/mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql \
		--with-pgsql-include=${LOCALBASE}/include \
		--with-pgsql-lib=${LOCALBASE}/lib
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

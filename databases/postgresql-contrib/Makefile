# New ports collection makefile for:	postgresql-contrib
# Date created:		June 10, 2003
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	postgresql-contrib
PORTREVISION=	0
CATEGORIES=	databases

MAINTAINER=	girgen@pingpong.net
COMMENT=	The contrib utilities from the PostgreSQL distribution

LIB_DEPENDS=	pq:${PORTSDIR}/${POSTGRESQL_PORT}

POSTGRESQL_PORT?=	databases/postgresql7
POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../../${POSTGRESQL_PORT}/Makefile>

INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include \
		--docdir=${PREFIX}/share/doc/postgresql
MAKE_ARGS=	-C contrib

pre-build:
	cd ${WRKSRC}/src/backend ;\
	${GMAKE} ../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h

post-install:
	@ ${INSTALL_DATA} ${WRKSRC}/contrib/README \
			  ${PREFIX}/share/doc/postgresql/contrib/README
	@ ${ECHO} ==================================== ;\
	  ${SED} -e "s,/usr/local,${PREFIX},g"  ${PKGDIR}/pkg-message ;\
	  ${ECHO} ====================================

.include <bsd.port.mk>

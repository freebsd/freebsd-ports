# ex:ts=8
# New ports collection makefile for:	libdbi
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libdbi
PORTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://linux.ucla.edu/~dap24/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	seanc@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql \
			--with-mysql-incdir=${LOCALBASE}/include \
			--with-mysql-libdir=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf \
		${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/driver-guide
	${INSTALL_DATA} ${WRKSRC}/doc/driver-guide/*.html \
		${DOCSDIR}/driver-guide
	@${MKDIR} ${DOCSDIR}/programmers-guide
	${INSTALL_DATA} ${WRKSRC}/doc/programmers-guide/*.html \
		${DOCSDIR}/programmers-guide
.endif

.include <bsd.port.mk>

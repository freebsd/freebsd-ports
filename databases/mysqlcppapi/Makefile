# ports collection makefile for:	mysqlcppapi
# Date created:				4 August 2004
# Whom:					Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	mysqlcppapi
PORTVERSION=	1.9.3
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=mysqlcppapi

MAINTAINER=	gaoj@cpsc.ucalgary.ca
COMMENT=	A fork of mysql++ C++ API for MySQL

USE_MYSQL=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	pkgconfig gnomehack
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/stlport" \
		LDFLAGS="-L${LOCALBASE}/lib -lstlport_gcc ${PTHREAD_LIBS}"
.else
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE}
INSTALLS_SHLIB=	yes

post-patch:
	${REINPLACE_CMD} s/libmysqlcppapi-1.9/libmysqlcppapi/g \
		${WRKSRC}/mysqlcppapi/Makefile.in ${WRKSRC}/examples/Makefile.in
	${FIND} ${WRKSRC}/mysqlcppapi -name Makefile.in \
       		-exec ${REINPLACE_CMD} -e \
		'/^library_includedir =/s,\$$(GENERIC_LIBRARY_NAME)-2.0/,,g' '{}' \;

.include <bsd.port.post.mk>

# ports collection makefile for:	mysqlcppapi
# Date created:				4 August 2004
# Whom:					Jie Gao <gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	mysqlcppapi
PORTVERSION=	1.9.3
PORTREVISION=	3
CATEGORIES=	databases devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%202/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fork of mysql++ C++ API for MySQL

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config

USE_AUTOTOOLS=	libtool
USE_MYSQL=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-mysql=${LOCALBASE}
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} s/libmysqlcppapi-1.9/libmysqlcppapi/g \
		${WRKSRC}/mysqlcppapi/Makefile.in ${WRKSRC}/examples/Makefile.in
	${FIND} ${WRKSRC}/mysqlcppapi -name Makefile.in \
		-exec ${REINPLACE_CMD} -e \
		'/^library_includedir =/s,\$$(GENERIC_LIBRARY_NAME)-2.0/,,g' '{}' \;

.include <bsd.port.mk>

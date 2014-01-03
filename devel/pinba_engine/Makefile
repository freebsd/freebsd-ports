# Created by: raven428 <raven428@gmail.com>
# $FreeBSD$

PORTNAME=	pinba_engine
PORTVERSION=	2011.08.18
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/tony2001/pinba_engine/tarball/${GITVERSION}/
DISTNAME=	tony2001-pinba_engine-${GITVERSION}

MAINTAINER=	raven428@gmail.com
COMMENT=	Mysql-engine part of statistics server for PHP

BUILD_DEPENDS=	${LOCALBASE}/include/google/protobuf/descriptor.h:${PORTSDIR}/devel/protobuf \
 		${LOCALBASE}/include/event.h:${PORTSDIR}/devel/libevent \
		${LOCALBASE}/include/Judy.h:${PORTSDIR}/devel/judy \
		${LOCALBASE}/lib/mysql/plugin:${PORTSDIR}/${_MYSQL_SERVER} \
 		${NONEXISTENT}:${PORTSDIR}/${_MYSQL_SERVER}:configure \
		bison:${PORTSDIR}/devel/bison \
		cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	protobuf:${PORTSDIR}/devel/protobuf

GITVERSION=	3a0cb51

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	50

MYSQL_WRKSRC=	$$(cd ${PORTSDIR}/${_MYSQL_SERVER} && ${MAKE} -V WRKSRC)

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
USE_LDCONFIG=	${PREFIX}/lib/mysql/plugin

AUTOMAKE_ARGS+=	--add-missing --copy --force-missing
LIBTOOLIZE_ARGS+=--force --copy
ACLOCAL_ARGS+=	-I ${LOCALBASE}/share/aclocal

CONFIGURE_ARGS+=	\
		--with-mysql=${MYSQL_WRKSRC} \
		--libdir=${PREFIX}/lib/mysql/plugin
CFLAGS+=	-I${LOCALBASE}/include/mysql

SUB_FILES=	pkg-message
.if !defined(NOPORTDOCS)
PORTDOCS=	NEWS TODO README
.endif

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	@${INSTALL} ${WRKSRC}/default_tables.sql ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${DOCSDIR}
.endif
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>

# New ports collection makefile for:	pinba_engine
# Date created:				24 Dec 2009
# Whom:					raven428 <raven428@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pinba_engine
PORTVERSION=	2009.12.24
CATEGORIES=	devel
MASTER_SITES=	http://aston2.com/~raven/unix/pinba/ \
 		http://mks-chel.ru/~raven/FreeBSD/pinba/
DISTNAME=	pinba_engine-200912240755

MAINTAINER=	raven428@gmail.com
COMMENT=	Mysql-engine part of statistics server for PHP

BUILD_DEPENDS=	${LOCALBASE}/include/google/protobuf/descriptor.h:${PORTSDIR}/devel/protobuf \
 		${LOCALBASE}/include/event.h:${PORTSDIR}/devel/libevent \
		${LOCALBASE}/include/Judy.h:${PORTSDIR}/devel/judy \
		${LOCALBASE}/lib/mysql/plugin:${MYSQL_PORTDIR} \
 		${NONEXISTENT}:${MYSQL_PORTDIR}:configure

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_MYSQL=	yes
WANT_MYSQL_VER=	51
MYSQL_PORTDIR=	${PORTSDIR}/databases/mysql${MYSQL_VER}-server
MYSQL_WRKSRC=	$$(cd ${MYSQL_PORTDIR} && ${MAKE} -V WRKSRC)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
		--with-mysql=${MYSQL_WRKSRC} \
		--libdir=${PREFIX}/lib/mysql/plugin
CFLAGS+=	-I${LOCALBASE}/include/mysql
USE_LDCONFIG=	${PREFIX}/lib/mysql/plugin

SUB_FILES=	pkg-message
.if !defined(NOPORTDOCS)
PORTDOCS=	NEWS TODO README
.endif

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

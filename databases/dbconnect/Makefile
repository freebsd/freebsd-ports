# ex:ts=8
# New ports collection makefile for:	dbconnect
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbconnect
PORTVERSION=	0.2.0
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Use C++ object API to allow applications to connect to databases

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes

.if defined(WITH_MYSQL)
LIB_DEPENDS=	mysqlclient:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--with-mysql=yes --with-mysqldir=${LOCALBASE}
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.include <bsd.port.mk>

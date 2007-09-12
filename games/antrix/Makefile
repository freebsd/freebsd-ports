# New ports collection makefile for:	antrix
# Date created:				11 September 2007
# Whom:					Denisov Evgeniy <skillcoder@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	antrix
PORTVERSION=	1477
CATEGORIES=	games
MASTER_SITES=	http://skillcoder.narod.ru/wow/antrix/ \
		http://wtq.ru/wow/antrix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	skillcoder@mail.ru
COMMENT=	Free stable dedicated-server for World of Warcraft

BUILD_DEPENDS=	svn:${PORTSDIR}/devel/subversion

USE_AUTOTOOLS=	aclocal:19 libtoolize autoconf:261 autoheader:261 automake:19 libtool:15
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-a
USE_MYSQL=	yes
CFLAGS+=	-O0
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}/etc --datadir=${PREFIX}/share
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

run-autotools-automake:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS})

.include <bsd.port.mk>

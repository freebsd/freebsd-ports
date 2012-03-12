# New ports collection makefile for:	antrix
# Date created:				11 September 2007
# Whom:					Denisov Evgeniy <skillcoder@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	antrix
PORTVERSION=	1477
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://skillcoder.narod.ru/wow/antrix/ \
		http://wtq.ru/wow/antrix/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free stable dedicated-server for World of Warcraft

DEPRECATED=	no more public distfiles, abandoned upstream
EXPIRATION_DATE=	2012-06-01

BUILD_DEPENDS=	svn:${PORTSDIR}/devel/subversion

USE_AUTOTOOLS=	aclocal libtoolize autoconf autoheader automake libtool
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-a
USE_MYSQL=	yes
CFLAGS+=	-O0
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}/etc --datadir=${PREFIX}/share

run-autotools-automake:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS})

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>

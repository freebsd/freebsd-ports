# ports collection makefile for:	Berkeley DB v3
# Date created:				16 August 2000
# Whom:					Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	db3
PORTVERSION=	3.3.11
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/${PORTVERSION}/
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

MAINTAINER=	ozz@FreeBSD.org.ru

NO_LATEST_LINK=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

INSTALLS_SHLIB=		yes
#USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
#LIBTOOLFILES=		${CONFIGURE_SCRIPT}
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx \
			--prefix=${PREFIX} \
			--includedir=${PREFIX}/include/db3 \
			--target=${ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${CHMOD} 755 ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>

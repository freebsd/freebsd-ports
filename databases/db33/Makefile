# ports collection makefile for:	Berkeley DB v3
# Date created:				16 August 2000
# Whom:					Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	db3
PORTVERSION=	3.2.9
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/${PORTVERSION}/
DISTNAME=	db-${PORTVERSION}

MAINTAINER=	ozz@FreeBSD.org.ru

MANUAL_PACKAGE_BUILD=	incompatible with libc internal db calls
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

INSTALLS_SHLIB=		yes
USE_LIBTOOL=		yes
CONFIGURE_SCRIPT=	../dist/configure
LIBTOOLFILES=		${CONFIGURE_SCRIPT}
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx \
			--enable-dynamic \
			--prefix=${PREFIX} \
			--includedir=${PREFIX}/include/db3 \
			--target=$(ARCH)-unknown-freebsd$(OSREL)

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${CHMOD} 755 ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>

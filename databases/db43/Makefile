# ports collection makefile for:	Berkeley DB v4
# Date created:				16 August 2000
# Whom:					Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	db4
PORTVERSION=	4.0.14
#PORTREVISION=	2
#PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/${PORTVERSION}/
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

MAINTAINER=	ozz@FreeBSD.org.ru

#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	patch.${PORTVERSION}.1 patch.${PORTVERSION}.2
#PATCH_DIST_STRIP= -d ${WRKDIR}/${DISTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

INSTALLS_SHLIB=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx \
			--enable-dynamic \
			--prefix=${PREFIX} \
			--includedir=${PREFIX}/include/db4 \
			--target=${ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${CHMOD} 755 ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/../dist/configure

.include <bsd.port.mk>

# New ports collection makefile for:	pwlib
# Date created:		Fri Aug 22 07:11:44 GMT 2003
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pwlib152
PORTVERSION=	1.5.2
CATEGORIES=	devel
MASTER_SITES=	http://www.openh323.org/bin/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner
DISTNAME=	${NAME}_${PORTVERSION}

MAINTAINER=	db@db.net
COMMENT=	A cross platform C++ library, used by OpenH323

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${NAME}

NAME=		pwlib
USE_BISON=	yes
USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_AUTOTOOLS=	autoconf:259 autoconf:253:env
CONFIGURE_ENV=	OSRELEASE=${OSVERSION}
ALL_TARGET=	optnoshared
MAKE_ENV=	PWLIBDIR=${WRKDIR}/pwlib
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502101
ONLY_FOR_ARCHS=	i386
.endif

do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/samples/simple/obj_${OPSYS}_${THE_MACHTYPE}_r/simph323 ${PREFIX}/bin

.include <bsd.port.post.mk>

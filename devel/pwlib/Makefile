# New ports collection makefile for:	pwlib
# Date created:		Fri Aug 22 07:11:44 GMT 2003
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pwlib
PORTVERSION=	1.6.5
CATEGORIES=	devel
MASTER_SITES=	http://www.gnomemeeting.org/admin/downloads/latest/sources/sources/ \
		http://www.gnomemeeting.org/downloads/1.0/sources/sources/ \
		http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/
DISTNAME=	${PORTNAME}-v${PORTVERSION:C/\./_/g}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross platform C++ library, used by OpenH323

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BISON=	yes
USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_AUTOCONF_VER=	253
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

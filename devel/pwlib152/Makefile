# New ports collection makefile for:	pwlib
# Date created:		Fri Aug 22 07:11:44 GMT 2003
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pwlib
PORTVERSION=	1.5.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.openh323.org/bin/ \
		http://www.de.openh323.org/bin/ \
		http://www.gnomemeeting.org/downloads/0.98.0/sources/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	roger@freebsd.org
COMMENT=	A cross platform C++ library, used by OpenH323

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BISON=	yes

USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_OPENLDAP=	yes
WANT_AUTOCONF_VER=	253
CONFIGURE_ENV=	OSRELEASE=${OSVERSION}
ALL_TARGET=	optnoshared
MAKE_ENV=	PWLIBDIR=${WRKDIR}/pwlib
THE_MACHTYPE=	${ARCH:S/i386/x86/}
MAKE_ARGS=	OSTYPE=${OPSYS} MACHTYPE=${THE_MACHTYPE} OSRELEASE=${OSVERSION} CPLUS=${CXX}

ONLY_FOR_ARCHS=	i386

do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/samples/simple/obj_${OPSYS}_${THE_MACHTYPE}_r/simph323 ${PREFIX}/bin

.include <bsd.port.mk>

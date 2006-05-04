# New ports collection makefile for:	c_c++_reference.tar.gz
# Date created:        8 March 2000
# Whom:                imura@af.airnet.ne.jp
#
# $FreeBSD$
#

PORTNAME=	c_c++_reference
PORTVERSION=	2.0.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ee.fhm.edu/pub/unix/ide/KDevelop/
DISTNAME=	c_cpp_reference-${PORTVERSION}_for_KDE_3.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ reference manual for KDevelop

RUN_DEPENDS=	kdevelop:${PORTSDIR}/devel/kdevelop

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_KDELIBS_VER=	3
USE_GMAKE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e 's,-lqt,-lqt-mt -pthread,' ${WRKSRC}/configure

.include <bsd.port.mk>

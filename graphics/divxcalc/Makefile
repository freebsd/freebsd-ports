# ex:ts=8
# Ports collection makefile for:	divxcalc
# Date created:			Mar 21, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	divxcalc
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://axljab.homelinux.org/software/divxcalc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DivX Calculator

BUILD_DEPENDS=	aclocal:${PORTSDIR}/devel/automake \
		autoheader:${PORTSDIR}/devel/autoconf

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

pre-configure:
	@cd ${WRKSRC} && ${GMAKE} -f admin/Makefile.common

.include <bsd.port.mk>

# Ports collection makefile for:  skyeye
# Date created:			  Mon July 18, 2005
# Whom:				  Ruan Wei (iamayan@gmail.com)
#
# $FreeBSD$
#

PORTNAME=	skyeye
PORTVERSION=	1.2
PORTREVISION=	3
DISTVERSIONPREFIX=v
DISTVERSIONSUFFIX=_Rel
CATEGORIES=	emulators
MASTER_SITES=	http://download.gro.clinux.org/skyeye/

MAINTAINER=	iamayan@gmail.com
COMMENT=	An environment simulates typical ARM-base embedded computer systems

BUILD_DEPENDS=	${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty \
		${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd
RUN_DEPENDS=	${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty \
		${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/${PORTNAME}-v1

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binary/skyeye ${PREFIX}/bin

.include <bsd.port.post.mk>

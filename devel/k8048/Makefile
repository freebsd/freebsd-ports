# New ports collection makefile for:	k8048
# Date Created:		Oct 6 2007
# Whom:			Bruce M. Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	k8048
PORTVERSION=	0.1
CATEGORIES=	devel
MASTER_SITES=	http://dev.kewl.org/k8048/
DISTNAME=	$(PORTNAME)

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Programs Microchip PICs using Velleman K8048 board

USE_GMAKE=	yes

#BUILD_DEPENDS+=	gpasm:${PORTSDIR}/devel/gputils

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${BUILD_WRKSRC}/${PORTNAME} && ${GMAKE} all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${PORTNAME} \
			   ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>

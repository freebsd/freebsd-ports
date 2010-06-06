# New ports collection makefile for:	k8048
# Date Created:		Oct 6 2007
# Whom:			Bruce M. Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	k8048
PORTVERSION=	1.04
CATEGORIES=	devel
MASTER_SITES=	http://dev.kewl.org/k8048/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs Microchip PICs using Velleman K8048 board

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

#BUILD_DEPENDS+=	gpasm:${PORTSDIR}/devel/gputils

BIN_SYMLINKS=	bin/ktest bin/kdebug bin/k14 bin/k16
PLIST_FILES=	bin/${PORTNAME} ${BIN_SYMLINKS}

do-build:
	cd ${BUILD_WRKSRC}/${PORTNAME} && ${GMAKE} all

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}/${PORTNAME} \
			   ${PREFIX}/bin/${PORTNAME}

post-install:
.for i in ${BIN_SYMLINKS}
	cd ${PREFIX} && ${LN} -s ${PORTNAME} ${i}
.endfor

.include <bsd.port.mk>

# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	k8048
PORTVERSION=	2.09
CATEGORIES=	devel
MASTER_SITES=	http://dev.kewl.org/k8048/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs Microchip PICs using Velleman K8048 board

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	#empty - the makefile lacks an "all" target
MAKE_JOBS_SAFE=	yes

#BUILD_DEPENDS+=	gpasm:${PORTSDIR}/devel/gputils

BIN_SYMLINKS=	bin/ktest bin/kdebug bin/k14 bin/k16
PLIST_FILES=	bin/${PORTNAME} ${BIN_SYMLINKS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/${PORTNAME} \
	${PREFIX}/bin/${PORTNAME}

post-install:
.for i in ${BIN_SYMLINKS}
	cd ${PREFIX} && ${LN} -fs ${PORTNAME} ${i}
.endfor

.include <bsd.port.mk>

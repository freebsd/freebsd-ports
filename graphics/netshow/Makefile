# New ports collection makefile for:    netshow
# Version required:     2.00.251
# Date created:         Thu Jun 11 22:38:52 PDT 1998
# Whom:                 dburr@FreeBSD.ORG
#
# $Id: Makefile,v 1.3 1998/11/21 07:27:35 steve Exp $
#

DISTNAME=	netshow_linux
PKGNAME=	netshow-2.00.251
CATEGORIES=	graphics net
MASTER_SITES=	http://microsoft.com/netshow/download/en/beta/
EXTRACT_SUFX=	.gz

MAINTAINER=	dburr@FreeBSD.ORG

RUN_DEPENDS=	/compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

ONLY_FOR_ARCHS=	i386
RESTRICTED=	"Commercial software"
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

NO_BUILD=	yes

USE_X_PREFIX=	yes

pre-extract:
	@${MKDIR} ${WRKDIR}

do-extract:
	${GUNZIP_CMD} < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/netshow

do-patch:
	brandelf -t Linux ${WRKDIR}/netshow

do-install:
	${INSTALL} -c -o bin -g bin -m 555 ${WRKDIR}/netshow ${PREFIX}/bin/netshow

post-install:
	@cat ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

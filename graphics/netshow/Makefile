# New ports collection makefile for:    netshow
# Date created:         Thu Jun 11 22:38:52 PDT 1998
# Whom:                 dburr@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	netshow
PORTVERSION=	2.00.251
CATEGORIES=	graphics net linux
MASTER_SITES=	http://microsoft.com/netshow/download/en/beta/
DISTNAME=	netshow_linux
EXTRACT_SUFX=	.gz

MAINTAINER=	dburr@FreeBSD.org

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

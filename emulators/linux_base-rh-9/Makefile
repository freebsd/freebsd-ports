# New ports collection makefile for:    linux_lib
# Version required:	2.6
# Date created:         3 Nov 1995
# Whom:                 markm@FreeBSD.org
#
# $Id: Makefile,v 1.23 1999/01/06 04:27:54 simokawa Exp $
#

DISTNAME=	linux_lib-2.6.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://relay.nuxi.com/pub/FreeBSD/

MAINTAINER=	erich@FreeBSD.org

ONLY_FOR_ARCHS=	i386

PREFIX=		/compat/linux
NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_FILTER_SHLIBS=	yes

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	@zcat ${DISTDIR}/${DISTNAME}.tar.gz |(cd ${PREFIX}; pax -r)

post-install:
	-/compat/linux/sbin/ldconfig
	${MKDIR} ${PREFIX}/usr/lib/zoneinfo
	ln -sf /etc/localtime /${PREFIX}/usr/lib/zoneinfo/localtime

.include <bsd.port.mk>

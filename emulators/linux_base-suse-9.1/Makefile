# New ports collection makefile for:    linux_lib
# Version required:	2.1
# Date created:         
# Whom:                 erich@FreeBSD.org
#
# $Id: Makefile,v 1.20 1998/10/08 10:07:46 jkh Exp $
#

DISTNAME=	linux_lib-2.5
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	erich@FreeBSD.org

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

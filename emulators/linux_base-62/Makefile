# New ports collection makefile for:    linux_lib
# Version required:	2.6
# Date created:         3 Nov 1995
# Whom:                 markm@FreeBSD.org
#
# $Id: Makefile,v 1.24 1999/02/26 13:37:33 obrien Exp $
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
	${LN} -sf /etc/localtime /${PREFIX}/usr/lib/zoneinfo/localtime
	${MKDIR} ${PREFIX}/dev
	${LN} -sf /dev/console ${PREFIX}/dev/tty0
	${LN} -sf /dev/ttyv0 ${PREFIX}/dev/tty1
	${LN} -sf /dev/ttyv1 ${PREFIX}/dev/tty2
	${LN} -sf /dev/ttyv2 ${PREFIX}/dev/tty3
	${LN} -sf /dev/ttyv3 ${PREFIX}/dev/tty4
	${LN} -sf /dev/sysmouse ${PREFIX}/dev/mouse
	${LN} -sf /dev/psm0 ${PREFIX}/dev/psaux

.include <bsd.port.mk>

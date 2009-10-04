# New ports collection makefile for:	bmake
# Date created:				13 September 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bmake
PORTVERSION=	20090909
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/sjg/ \
	http://www.gtlib.cc.gatech.edu/pub/NetBSD/misc/sjg/ \
	ftp://ftp.uk.netbsd.org/pub/NetBSD/misc/sjg/ \
	ftp://ftp.de.netbsd.org/pub/NetBSD/misc/sjg/
DISTFILES=	bmake-${PORTVERSION}.tar.gz mk-20081111.tar.gz

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Portable version of NetBSD 'make' utility

MAN1=		bmake.1

do-build:
	${WRKDIR}/bmake/boot-strap -m ${WRKDIR}/mk FORCE_SYS_MK=Generic FORCE_BSD_MK=1 objdir=${WRKDIR}/obj

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/obj/bmake ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKDIR}/bmake/bmake.cat1 ${PREFIX}/man/man1/bmake.1
	${SH} ${WRKDIR}/mk/install-mk ${PREFIX}/share/mk

.include <bsd.port.mk>

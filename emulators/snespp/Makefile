# Ports collection makefile for:	snespp
# Date created:		16 April 2007
# Whom:			Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	snespp
PORTVERSION=	1.0
CATEGORIES=	emulators kld
MASTER_SITES=	http://www.cse.unsw.edu.au/~tbourke/software/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	timbob@bigpond.com
COMMENT=	Kernel module for SNES controllers on a parallel port

KMODDIR=	/boot/modules

NO_PACKAGE=	this port should be recompiled for a particular FreeBSD kernel
PLIST_SUB=	KMODDIR="${KMODDIR}"

MAN4=		snespp.4
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		versions of FreeBSD before 6.0 are not supported
.endif

do-install:
	@${INSTALL_MAN} ${WRKSRC}/snespp.4 ${PREFIX}/man/man4
	@${INSTALL_PROGRAM} ${WRKSRC}/snespp.ko ${KMODDIR}

.include <bsd.port.post.mk>

# New ports collection makefile for:	strace
# Date created:		Tue May 15 22:29:27 MSD 2001
# Whom:			Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	strace
PORTVERSION=	4.4.94
CATEGORIES=	devel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alex@rinet.ru
COMMENT=	A portable process tracer

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		strace.1

do-install:
	-${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/strace ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strace-graph ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/strace.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

# New ports collection makefile for:	strace
# Date created:		Tue May 15 22:29:27 MSD 2001
# Whom:			Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	strace
PORTVERSION=	4.4
CATEGORIES=	devel sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	alex@rinet.ru

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		strace.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/strace ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strace-graph ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/strace.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/strace
	${INSTALL_DATA} ${WRKSRC}/xlate.el ${PREFIX}/share/strace

.include <bsd.port.mk>

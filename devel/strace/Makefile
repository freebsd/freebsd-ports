# New ports collection makefile for:	strace
# Date created:		Tue May 15 22:29:27 MSD 2001
# Whom:			Alex Semenyaka <alexs@snark.rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	strace
PORTVERSION=	4.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alexs@snark.rinet.ru

GNU_CONFIGURE=	yes

MAN1=		strace.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/strace ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/strace-graph ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/strace.1 ${PREFIX}/man/man1
	-${MKDIR} ${PREFIX}/share/strace
	${INSTALL_DATA} ${WRKSRC}/xlate.el ${PREFIX}/share/strace

.include <bsd.port.mk>

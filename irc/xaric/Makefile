# New ports collection makefile for:	Xaric
# Date created:		14 Oct 01
# Whom:			alanp@unixpower.org
#
# $FreeBSD$
#

PORTNAME=	xaric
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://rf.cx/software/xaric/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC Client similer to BitchX or ircII

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		xaric.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on ${ARCH}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xaric ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xaric.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${DATADIR}/help

.include <bsd.port.post.mk>

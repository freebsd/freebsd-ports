# New ports collection makefile for:	Xaric
# Date created:		14 Oct 01
# Whom:			alanp@unixpower.org
#
# $FreeBSD$
#

PORTNAME=	xaric
PORTVERSION=	0.12.1
CATEGORIES=	irc
MASTER_SITES=	http://www.xaric.org/downloads/ \
		ftp://ftp.xaric.org/xaric/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC Client similer to BitchX or ircII

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		xaric.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xaric ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/xaric.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}/help
	${INSTALL_DATA} ${WRKSRC}/help/* ${DATADIR}/help

.include <bsd.port.mk>

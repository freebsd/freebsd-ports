# New ports collection makefile for:	telnet8
# Date created:		13 Feb 1999
# Whom:			Ching-Hong Wu <woju@freebsd.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	telnet
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

SRCDIR=		/usr/src/usr.bin/telnet

do-extract:
.if exists (${SRCDIR})
	@${MKDIR} ${WRKDIR}
	@${CP} -R ${SRCDIR} ${WRKSRC}
.else
BROKEN=	"You need to build this port with ${SRCDIR}"
.endif

MAN1=		zh-telnet.1

do-install:
	@cd ${WRKSRC}; \
	${CP} telnet.1 ${MAN1}; \
	${INSTALL_PROGRAM} ${WRKSRC}/telnet ${PREFIX}/bin/zh-telnet; \
	${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>

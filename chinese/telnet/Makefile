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

MAINTAINER=	leeym@FreeBSD.org

SRCDIR=		/usr/src/usr.bin/telnet
USE_REINPLACE=	yes

MAN1=		zh-telnet.1

do-extract:
.if exists (${SRCDIR})
	@${MKDIR} ${WRKDIR}
	@${CP} -R ${SRCDIR} ${WRKSRC}
	@${MKDIR} ${WRKSRC}/lib
	@${CP} -R /usr/src/lib/libtelnet ${WRKSRC}/lib
.else
BROKEN=	"You need to build this port with ${SRCDIR}"
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,/../..,,g' ${WRKSRC}/Makefile

pre-build:
	@cd ${WRKSRC}/lib/libtelnet && ${MAKE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/telnet ${PREFIX}/bin/zh-telnet
	@${INSTALL_MAN} ${WRKSRC}/telnet.1 ${PREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>

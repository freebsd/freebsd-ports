# New ports collection makefile for:	lftp
# Version required:			0.12.2
# Date created:				11 September 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1997/11/17 13:18:36 tg Exp $
#

DISTNAME=	lftp-0.12.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/file-transfer

MAINTAINER=	andy@icc.surw.chel.su

GNU_CONFIGURE=	yes
MAN1=		lftp.1 ftpget.1 parallelftp.1

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=		"Doesn't build under current"
.endif

do-install:
.for file in lftp ftpget parallelftp
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/doc/${file}.1 ${PREFIX}/man/man1
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf
	@ ${MKDIR} ${PREFIX}/share/doc/lftp
.for file in NEWS README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/lftp
.endfor

.include <bsd.port.mk>

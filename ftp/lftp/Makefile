# New ports collection makefile for:	lftp
# Version required:			0.13.2
# Date created:				11 September 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1997/11/30 00:24:02 jseger Exp $
#

DISTNAME=	lftp-0.13.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/file-transfer

MAINTAINER=	andy@icc.surw.chel.su

GNU_CONFIGURE=	yes
MAN1=		lftp.1 ftpget.1

do-install:
.for file in lftp ftpget
	@ ${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/doc/${file}.1 ${PREFIX}/man/man1
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf
	@ ${MKDIR} ${PREFIX}/share/doc/lftp
.for file in COPYING NEWS README THANKS TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/lftp
.endfor

.include <bsd.port.mk>

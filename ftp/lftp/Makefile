# New ports collection makefile for:	lftp
# Version required:			1.0.1
# Date created:				11 September 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.8 1998/05/10 16:45:29 steve Exp $
#

DISTNAME=	lftp-1.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/file-transfer

MAINTAINER=	andy@icc.surw.chel.su

GNU_CONFIGURE=	yes
MAN1=		lftp.1 ftpget.1

post-install:
	@ ${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf.sample
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/lftp
.for file in COPYING FAQ NEWS README THANKS TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/lftp
.endfor
.endif

.include <bsd.port.mk>

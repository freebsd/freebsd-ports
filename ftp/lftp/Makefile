# New ports collection makefile for:	lftp
# Version required:			2.1.9
# Date created:				11 September 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	lftp-2.1.9
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/net/ftp/client/lftp/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/network/file-transfer

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

MAN1=		lftp.1 ftpget.1

post-extract:
	@ ${CP} ${FILESDIR}/nameser.h ${WRKSRC}/src

post-install:
	@ ${INSTALL_DATA} ${WRKSRC}/lftp.conf ${PREFIX}/etc/lftp.conf.sample
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/lftp
.for file in COPYING FAQ NEWS README THANKS TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/lftp
.endfor
.endif

.include <bsd.port.mk>

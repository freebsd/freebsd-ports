# New ports collection makefile for:	yale-tftpd
# Version required:	3.0
# Date created:		Oct 8, 1994
# Whom:			pst
#
# $Id: Makefile,v 1.10 1998/10/14 03:30:00 jseger Exp $
#

DISTNAME=	yale-tftpd-3.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/net/yale-tftpd/

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=
MAN8=		tftpd.8
MANCOMPRESSED=	yes

pre-build:
	(cd ${WRKSRC}/classes; ${MAKE})

.include <bsd.port.mk>

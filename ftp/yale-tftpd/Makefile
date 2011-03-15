# New ports collection makefile for:	yale-tftpd
# Date created:		Oct 8, 1994
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	yale-tftpd
PORTVERSION=	3.0
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/net/yale-tftpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced tftpd(8) from Yale University and cisco Systems

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_WRKSUBDIR=
MAKE_ARGS=	ETCDIR=${PREFIX}/etc BINDIR=${PREFIX}/libexec MANDIR=${PREFIX}/man/man

MAN8=		tftpd.8
MANCOMPRESSED=	yes
PLIST_FILES=	libexec/tftpd

pre-build:
	(cd ${WRKSRC}/classes; ${MAKE})

.include <bsd.port.mk>

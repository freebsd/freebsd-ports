# New ports collection makefile for:	tcs
# Version required:	1.44
# Date created:		18 Oct 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	tcs
PKGNAME=	tcs-19950325
CATEGORIES=	converters plan9
MASTER_SITES= 	ftp://plan9.bell-labs.com/plan9/unixsrc/ \
		ftp://ftp.gwdg.de/pub/gnu2/plan9/unixsrc/
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	kuriyama@FreeBSD.org

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS= | ${SH}
ALL_TARGET=	tcs
MAN1=		tcs.1

do-install:
	@${INSTALL_MAN} ${WRKSRC}/tcs.1 ${PREFIX}/man/man1
	@${INSTALL_PROGRAM} ${WRKSRC}/tcs ${PREFIX}/bin

.include <bsd.port.mk>

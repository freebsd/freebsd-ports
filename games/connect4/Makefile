# New ports collection makefile for:  connect4 
# Version required:	3.2
# Date created:		Thu May  8 16:41:01 EST 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
# FreeBSD Version:	2.1.5-RELEASE
#
# $Id: Makefile,v 1.1.1.1 1997/06/04 03:21:12 asami Exp $
#
      
DISTNAME=	connect4
PKGNAME=	connect4-3.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.gu.kiev.ua/pub/cdrom5/games/volume6/ \
		ftp://scitsc.wlv.ac.uk/pub/infomagic/usenet/games/volume6/
EXTRACT_SUFX=	""

MAINTAINER=	sutton@aardvark.apana.org.au

BUILD_DEPENDS=		gunshar:${PORTSDIR}/archivers/gshar+gunshar

EXTRACT_CMD=		gunshar
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
MAN6=		connect4.6

MANDIR=		${PREFIX}/man/man
LIBDIR=		${PREFIX}/lib

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/c4 ${PREFIX}/bin/connect4
		${MKDIR} ${LIBDIR}/connect4
		${INSTALL_DATA} -m 666 /dev/null ${LIBDIR}/connect4/scores
		${INSTALL_MAN} ${FILESDIR}/connect4.6 ${MANDIR}6/

.include <bsd.port.mk>

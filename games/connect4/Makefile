# New ports collection makefile for:  connect4
# Date created:		Thu May  8 16:41:01 EST 1997
# Whom:			Joel Sutton <jsutton@bbcon.com.au>
#
# $FreeBSD$
#

PORTNAME=	connect4
PORTVERSION=	3.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.gu.kiev.ua/pub/cdrom5/games/volume6/ \
		ftp://scitsc.wlv.ac.uk/pub/infomagic/usenet/games/volume6/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	""

MAINTAINER=	ports@freebsd.org

BUILD_DEPENDS=		gunshar:${PORTSDIR}/archivers/gshar+gunshar

EXTRACT_CMD=		gunshar
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
MAN6=		connect4.6

MANDIR=		${PREFIX}/man/man
LIBDIR=		${PREFIX}/lib

do-install:
		${INSTALL_PROGRAM} -m 2755 -o root -g games ${WRKSRC}/c4 ${PREFIX}/bin/connect4
		${MKDIR} ${LIBDIR}/connect4
		${INSTALL_DATA} -m 664 -o root -g games /dev/null ${LIBDIR}/connect4/scores
		${INSTALL_MAN} ${FILESDIR}/connect4.6 ${MANDIR}6/

.include <bsd.port.mk>

# New ports collection makefile for:	id3v2
# Date created:		10 Oct 2001
# Whom:			David MacKenzie <djm@pix.net>
#
# $FreeBSD$
#

PORTNAME=	id3v2
PORTVERSION=	0.1.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	id3v2

MAINTAINER=	djm@pix.net

LIB_DEPENDS=	id3-3.8.2:${PORTSDIR}/audio/id3lib \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

MAN1=		id3v2.1

do-install:
                ${INSTALL_PROGRAM} ${WRKSRC}/id3v2 ${PREFIX}/bin
                ${INSTALL_MAN} ${WRKSRC}/id3v2.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

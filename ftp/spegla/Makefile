# ex:ts=8
# New ports collection makefile for:    spegla
# Date created:         Sun Apr 19 16:17:25 PDT 1998
# Whom:                 Jordan Hubbard <jkh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spegla
PORTVERSION=	1.1p4
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.luth.se/pub/unix/mirror/ \
		ftp://subzero.campus.luth.se/pub/spegla/

MAINTAINER=	jkh@FreeBSD.org

MANCOMPRESSED=	yes
MAN1=		spegla.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/spegla
	${INSTALL_DATA} ${WRKSRC}/freebsd.org ${PREFIX}/share/examples/spegla

.include <bsd.port.mk>

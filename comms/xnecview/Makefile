# New ports collection makefile for:	xnecview
# Date created:		2006-03-18
# Whom:				Søren Straarup <xride@x12.dk>
#
# $FreeBSD$

PORTNAME=	xnecview
PORTVERSION=	1.35
PORTREVISION=	3
CATEGORIES=	comms hamradio
MASTER_SITES=	http://wwwhome.cs.utwente.nl/%7Eptdeboer/ham/xnecview/
EXTRACT_SUFX=	.tgz

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A X viewer of nec2c data

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	nec2c:${PORTSDIR}/comms/nec2c

USE_GNOME=	gtk20
USE_GMAKE=	yes

MAKE_ENV=	LDFLAGS="${LDFLAGS}"

MAN1=		xnecview.1
PLIST_FILES=	bin/xnecview

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xnecview ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xnecview.man ${MANPREFIX}/man/man1/xnecview.1

.include <bsd.port.mk>

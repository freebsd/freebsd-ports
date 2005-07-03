# New ports collection makefile for:	gputils
# Date created:				21 Jan 2002
# Whom:					Samuel Tardieu <sam@rfc1149.net>
#
# $FreeBSD$
#

PORTNAME=	gputils
PORTVERSION=	0.13.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sam@rfc1149.net
COMMENT=	GPUTILS is a set of utilities for Microchip PIC microcontrollers

GNU_CONFIGURE=	yes

MAN1=	gpasm.1 gpdasm.1 gplib.1 gplink.1 gpstrip.1 gputils.1 gpvc.1 gpvo.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ext in ps pdf lyx
	@${INSTALL_DATA} ${WRKSRC}/doc/gputils.${ext} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

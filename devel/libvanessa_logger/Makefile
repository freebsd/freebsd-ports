# New ports collection makefile for:	libvanessa_logger
# Date created:		28 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	libvanessa_logger
PORTVERSION=	0.0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.vergenet.net/linux/vanessa/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	vanessa_logger/${PORTVERSION}
DISTNAME=	vanessa_logger-${PORTVERSION}

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	Library that provides a generic logging layer

INSTALLS_SHLIB=	YES
GNU_CONFIGURE=	YES

post-patch:
	@${REINPLACE_CMD} -e 's,^loop:,loop: ;,' \
			${WRKSRC}/${PORTNAME}/vanessa_logger.c
.include <bsd.port.mk>

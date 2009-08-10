# New ports collection makefile for:	libburn
# Date created:		2008 November 06
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	libburn
PORTVERSION=	0.6.8
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTFILES=	${PORTNAME}-${PORTVERSION}.pl00${EXTRACT_SUFX}

MAINTAINER=	fbsd@opal.com
COMMENT=	Libburnia library to read/write optical discs

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	LIBS="-lcam"

USE_LDCONFIG=	yes
MAN1=		cdrskin.1

.include <bsd.port.mk>

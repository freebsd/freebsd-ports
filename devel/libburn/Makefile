# New ports collection makefile for:	libburn
# Date created:		2008 November 06
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	libburn
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Libburnia library to read/write optical discs

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		cdrskin.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure

.include <bsd.port.mk>

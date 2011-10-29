# New ports collection makefile for:	libburn
# Date created:		2008 November 06
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	libburn
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://files.libburnia-project.org/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}.pl01

MAINTAINER=	shuvaev@physik.uni-wuerzburg.de
COMMENT=	Libburnia library to read/write optical discs

WITH_FBSD10_FIX=yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		cdrskin.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/configure

.include <bsd.port.mk>

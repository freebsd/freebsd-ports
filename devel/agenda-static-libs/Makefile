# New ports collection makefile for:	agenda-static-libs
# Date created:		20 October 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	agenda-static-libs
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/agenda/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Static libraries which are needed to develop for Agenda VR3 PDA

DEPRECATED=	Agenda VR3 is dead for long time
EXPIRATION_DATE=2007-05-20

RUN_DEPENDS=	${PREFIX}/${TARGET_PLATFORM}/include/stdio.h:${PORTSDIR}/devel/agenda-headers

USE_BZIP2=	yes

TARGET_PLATFORM=mipsel-linux
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && tar --exclude '*.orig' -cf - *) \
		| (cd ${PREFIX}/${TARGET_PLATFORM} && tar xf -)

.include <bsd.port.mk>

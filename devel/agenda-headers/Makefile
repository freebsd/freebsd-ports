# New ports collection makefile for:	agenda-headers
# Date created:		14 June 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	agenda-headers
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/agenda/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	All headers which are needed to develop for Agenda VR3 PDA

RUN_DEPENDS=	${PREFIX}/${TARGET_PLATFORM}/include/linux/errno.h:${PORTSDIR}/devel/${TARGET_PLATFORM}-kernel-headers

TARGET_PLATFORM=mipsel-linux
USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && tar --exclude '*.orig' -cf - *) \
		| (cd ${PREFIX}/${TARGET_PLATFORM} && tar xf -)

.include <bsd.port.mk>

# Ports collection makefile for:	memcheck
# Date created:				Mon Sep 2, 2002
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	memcheck
PORTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.sound.net/~hald/projects/memcheck/

MAINTAINER=	demon@FreeBSD.org

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
.for file in memcheck.c tmemcheck.c
	@${REINPLACE_CMD} -e 's#<malloc.h>#<stdlib.h>#g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>

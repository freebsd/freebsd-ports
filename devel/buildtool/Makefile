# New ports collection makefile for:    buildtool
# Date created:         Tue Aug 27 22:11:08 PDT 2002
# Whom:                 Jos Backus <jos@catnook.com>
#
# $FreeBSD$
#

PORTNAME=	buildtool
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jos@catnook.com

MAN1=		buildtool.1

do-configure:
	@cd ${WRKSRC} \
	&& ./configure -p ${PREFIX}

.include <bsd.port.mk>

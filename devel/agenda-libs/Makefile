# New ports collection makefile for:	agenda-libs
# Date created:		14 June 2001
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	agenda-libs
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	lev@FreeBSD.org
COMMENT=	All libraries which are needed to develop for Agenda VR3 PDA

DEPRECATED=	Agenda VR3 is dead for long time
EXPIRATION_DATE=2007-05-20

RUN_DEPENDS=	${LOCALBASE}/mipsel-linux/lib/libc.a:${PORTSDIR}/devel/agenda-static-libs \
		${LOCALBASE}/mipsel-linux/lib/snow/libc.1.sso:${PORTSDIR}/devel/agenda-snow-libs

NO_BUILD=	yes

do-install:

.include <bsd.port.mk>

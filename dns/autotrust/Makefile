# New ports collection makefile for:	autotrust
# Date created:		2010-01-09
# Whom:			Jaap Akkerhuis <jaap@nlnetlabs.nl>
#
# $FreeBSD$
#

PORTNAME=	autotrust
PORTVERSION=	0.3.1
CATEGORIES=	dns
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/autotrust/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jaap@bartok.nlnetlabs.nl
COMMENT=	A a tool to automatically update DNSSEC trust anchors

BUILD_DEPENDS+=	ldns:${PORTSDIR}/dns/ldns
BUILD_DEPENDS+=	unbound:${PORTSDIR}/dns/unbound

MAN8=		autotrust.8

PLIST_FILES=	sbin/autotrust \
		etc/autotrust/autotrust.conf.sample
PLIST_DIRS=	etc/autotrust

GNU_CONFIGURE=	yes

.include <bsd.port.mk>

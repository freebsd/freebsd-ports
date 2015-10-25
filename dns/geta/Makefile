# Created by: sumikawa
# $FreeBSD$

PORTNAME=	geta
PORTVERSION=	19990419
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/
DISTNAME=	pping-${PORTVERSION}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Geta(GET Address) - Simple IPv4/IPv6 address resolving tool

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
WRKSRC=		${WRKDIR}/pping
GNU_CONFIGURE=	yes
USES=		perl5
USE_PERL5=	build

PLIST_FILES=		bin/geta

.include <bsd.port.mk>

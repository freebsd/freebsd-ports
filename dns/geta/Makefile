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

WRKSRC=		${WRKDIR}/pping
GNU_CONFIGURE=	yes
USES=		perl5
USE_PERL5=	build

NO_INSTALL_MANPAGES=	yes
PLIST_FILES=		bin/geta

.include <bsd.port.mk>

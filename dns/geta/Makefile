# New ports collection makefile for:	geta
# Date created:				5 Nov 2001
# Whom:					sumikawa
#
# $FreeBSD$
#

PORTNAME=	geta
PORTVERSION=	19990419
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/
DISTNAME=	pping-${PORTVERSION}

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Geta(GET Address) - Simple IPv4/IPv6 address resolving tool

WRKSRC=		${WRKDIR}/pping
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes

NO_INSTALL_MANPAGES=	yes
PLIST_FILES=		bin/geta

.include <bsd.port.mk>

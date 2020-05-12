# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	when
PORTVERSION=	1.1.40
CATEGORIES=	deskutils

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Simple personal calendar

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	bcrowell
GH_TAGNAME=	5de0120

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	when

MAKE_ARGS+=	prefix=${PREFIX} \
		MANDIR=${MANPREFIX}/man/man1

.include <bsd.port.mk>

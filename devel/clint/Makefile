# Created by: ijliao
# $FreeBSD$

PORTNAME=	clint
PORTVERSION=	0.1.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Static source code checker for C++

LICENSE=	GPLv2

USE_AUTOTOOLS=	libtool
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
USE_LDCONFIG=	yes

INFO=		clint

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-pedantic||g ; \
		 s|-ldl||g'

.include <bsd.port.mk>

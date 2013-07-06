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
USE_PYTHON=	-2.7
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--enable-python=${LOCALBASE}/bin/python2
USE_LDCONFIG=	yes

USES=	gmake

INFO=		clint

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl||g'

.include <bsd.port.mk>

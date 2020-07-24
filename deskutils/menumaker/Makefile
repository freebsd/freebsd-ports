# Created by: alepulver@FreeBSD.org
# $FreeBSD$

PORTNAME=	menumaker
PORTVERSION=	0.99.12
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Menu generator for X Window Managers and desktop environments

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake python

GNU_CONFIGURE=	yes
NO_ARCH=	yes

LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		mmaker

post-install:
		@${REINPLACE_CMD} -i '' -e '1s|#!.*|#!${PYTHON_CMD}|' \
			${STAGEDIR}${LOCALBASE}/bin/mmaker

.include <bsd.port.mk>

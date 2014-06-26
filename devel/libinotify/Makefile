# Created by: stas
# $FreeBSD$

PORTNAME=	libinotify
PORTVERSION=	20140622
CATEGORIES=	devel

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Kevent based inotify compatible library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	dmatveev
GH_PROJECT=	libinotify-kqueue
GH_COMMIT=	d775062
GH_TAGNAME=	${GH_COMMIT}

USE_LDCONFIG=	yes

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${TOUCH} ${WRKSRC}/config.h

.include <bsd.port.mk>

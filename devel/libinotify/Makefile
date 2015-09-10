# Created by: stas
# $FreeBSD$

PORTNAME=	libinotify
PORTVERSION=	20150516
CATEGORIES=	devel

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Kevent based inotify compatible library

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	dmatveev
GH_PROJECT=	libinotify-kqueue
GH_TAGNAME=	f4a092a

USE_LDCONFIG=	yes

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${TOUCH} ${WRKSRC}/config.h
	@echo "#define HAVE_PTHREAD_BARRIER 1" >> ${WRKSRC}/config.h
	@echo "#define BUILD_LIBRARY 1" >> ${WRKSRC}/config.h
	@echo "#include <sys/tree.h>" >> ${WRKSRC}/config.h

.include <bsd.port.mk>

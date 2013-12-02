# Created by: jasone
# $FreeBSD$

PORTNAME=	libedit
PORTVERSION=	2.6.10
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.astron.com/pub/libedit/ \
		http://www.canonware.com/download/libedit/

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Command line editing library

LICENSE=	BSD

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-extract:
	${MV} ${WRKSRC}/readline ${WRKSRC}/editline

post-patch:
	@${REINPLACE_CMD} -e 's|$$(PREFIX)|$$(DESTDIR)&|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|CFLAGS -O|CFLAGS|g ; \
		 s|MAJOR="2"|MAJOR="6"|g' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libedit.so

.include <bsd.port.mk>

# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libexecinfo
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	LOCAL/itetcu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for inspecting program's backtrace

LICENSE=	BSD2CLAUSE

USES=		tar:bzip2 uidfix
USE_LDCONFIG=	yes
MAKE_FLAGS=	LIBDIR=${PREFIX}/lib \
		INCLUDEDIR=${PREFIX}/include

CFLAGS+=	-fno-omit-frame-pointer

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

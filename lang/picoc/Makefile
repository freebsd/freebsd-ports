# $FreeBSD$

PORTNAME=	picoc
PORTVERSION=	2.1
CATEGORIES=	lang devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very small C interpreter for scripting

LICENSE=	BSD

USES=		gmake readline tar:bzip2

PLIST_FILES=	bin/picoc

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
CFLAGS+=	-DUNIX_HOST

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picoc ${STAGEDIR}${PREFIX}/bin/picoc

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	fmake
PORTVERSION=	r250982
CATEGORIES=	devel
MASTER_SITES=	LOCAL/crees/${PORTNAME}/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Legacy FreeBSD pmake

LICENSE=	BSD3CLAUSE # UCB third clause nullified

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

MAKE_ARGS+=	PROG=fmake MAN=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/make.1 \
		${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>

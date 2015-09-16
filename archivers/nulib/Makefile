# Created by: Steven Wallace <swallace@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nulib
PORTVERSION=	3.25
CATEGORIES=	archivers
MASTER_SITES=	LOCAL/jseger
DISTNAME=	nulib325

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NuFX archive utility

USES=		tar:Z
WRKSRC=		${WRKDIR}/nulib
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}/${MANPREFIX}/man/man1

.include <bsd.port.mk>

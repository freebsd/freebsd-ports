PORTNAME=	f77flow
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SUNSITE/devel/lang/fortran

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyze the structure of a fortran77 program

ALL_TARGET=
PLIST_FILES=	bin/flow man/man1/flow.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flow ${STAGEDIR}${PREFIX}/bin/flow
	${INSTALL_MAN} ${WRKSRC}/flow.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>

PORTNAME=	fondu
PORTVERSION=	051010
CATEGORIES=	converters
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}
DISTNAME=	${PORTNAME}_src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Series of programs to interconvert between mac fonts

LICENSE=	BSD3CLAUSE

HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

BINS=		fondu ufond showfond dfont2res tobin frombin lumper setfondname
MANPAGES=	fondu ufond showfond dfont2res tobin frombin lumper

do-install:
.for f in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>

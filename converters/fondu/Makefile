PORTNAME=	fondu
PORTVERSION=	051010
CATEGORIES=	converters
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}
DISTNAME=	${PORTNAME}_src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Series of programs to interconvert between mac fonts
WWW=		https://fondu.sourceforge.net/

LICENSE=	BSD3CLAUSE

USES=		tar:tgz

HAS_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

BINS=		fondu ufond showfond dfont2res tobin frombin lumper setfondname
MANPAGES=	fondu ufond showfond dfont2res tobin frombin lumper

do-install:
.for f in ${BINS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endfor

.include <bsd.port.mk>

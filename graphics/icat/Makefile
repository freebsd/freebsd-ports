# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icat
PORTVERSION=	0.4
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Displays images in 256-color capable terminals

USES=		gmake dos2unix
USE_EFL=	imlib2
USE_GITHUB=	yes
GH_ACCOUNT=	atextor
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	e8bee81

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-${GH_COMMIT}

PLIST_FILES=	bin/icat

CONFLICTS=	sleuthkit-[0-9]*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

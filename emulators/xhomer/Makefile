# Created by: trasz
# $FreeBSD$

PORTNAME=	xhomer
DISTVERSION=	9-16-06
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://xhomer.isani.org/xhomer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator for the DEC Pro 350 computer

USES=		gmake tar:tgz
USE_XORG=	xt sm ice xext x11
ALL_TARGET=	clean xhomer
INSTALL_TARGET=
CFLAGS+=	-Wall -ffloat-store
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	bin/xhomer %%EXAMPLESDIR%%/xhomer.cfg
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	README LICENSE SIMH

MAKE_JOBS_UNSAFE=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/xhomer ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xhomer.cfg ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

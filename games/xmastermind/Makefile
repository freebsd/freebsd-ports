# Whom: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xmastermind
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/strategy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mastermind game for X Window System

LICENSE=	GPLv2

LIB_DEPENDS=	forms:${PORTSDIR}/x11-toolkits/xforms

USE_XORG=	x11 xpm
MAKE_ENV=	GRAPHLIBS="${LDFLAGS}"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lforms -lXpm -lX11

PORTDOCS=	BUGS README.for.developers README.for.users
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CC/s| =| ?=| ; \
		 /^CFLAGS/s| =| ?=| ; \
		 /^GRAPHLIBS/s| =| ?=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|' ${WRKSRC}/list.h

.include <bsd.port.options.mk>

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>

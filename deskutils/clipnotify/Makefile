# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clipnotify
DISTVERSION=	1.0.2
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Program to notify on new X clipboard events

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg

PLIST_FILES=	bin/${PORTNAME}

USE_XORG=	x11 xfixes

USE_GITHUB=	yes
GH_ACCOUNT=	cdown

post-extract:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,$${LOCALBASE},g' ${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

PORTNAME=	clipnotify
DISTVERSION=	1.0.2-6
DISTVERSIONSUFFIX=	-g25ba143
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Program to notify on new X clipboard events
WWW=		https://github.com/cdown/clipnotify

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	cdown
USE_XORG=	x11 xfixes

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,$${LOCALBASE},g' ${WRKSRC}/Makefile

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

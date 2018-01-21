# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flameshot
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful yet simple to use screenshot software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

GH_ACCOUNT=	lupoDharkael

INSTALL_ICONS=	yes

USES=		qmake
USE_GCC=	yes
USE_GITHUB=	yes
USE_GL=		gl
USE_QT5=	core dbus gui linguist network widgets

post-patch:
		@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},1' \
			${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>

# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	creox
PORTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	audio kde

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime sound processor

LICENSE=	GPLv2

LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

USE_GITHUB=	yes
GH_ACCOUNT=	laudrup
GH_PROJECT=	Creox4
GH_TAGNAME=	0.3
GH_COMMIT=	8e27483

USES=		cmake:outsource
USE_KDE4=	automoc4 kdelibs kdeprefix
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XORG=	xft xpm

post-patch:
	@${REINPLACE_CMD} -e \
		'/-Wno-unused-but-set-variable/d' ${WRKSRC}/CMakeLists.txt
# FreeBSD does not have exp10f(3), use powf(3) instead
	@${GREP} -lR "exp10f(" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|exp10f(|powf(10.,|'

.include <bsd.port.mk>

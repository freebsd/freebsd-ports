# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	creox
PORTVERSION=	0.3
PORTREVISION=	6
CATEGORIES=	audio kde

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime sound processor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libjack.so:audio/jack

USE_GITHUB=	yes
GH_ACCOUNT=	laudrup
GH_PROJECT=	Creox4

USES=		cmake kde:4 qt:4
USE_KDE=	automoc4 kdelibs
USE_QT=		moc_build qmake_build rcc_build uic_build
USE_XORG=	xft xpm
USE_CXXSTD=	gnu++98

post-patch:
	@${REINPLACE_CMD} -e \
		'/-Wno-unused-but-set-variable/d' ${WRKSRC}/CMakeLists.txt
# FreeBSD does not have exp10f(3), use powf(3) instead
	@${GREP} -lR "exp10f(" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|exp10f(|powf(10.,|'

.include <bsd.port.mk>

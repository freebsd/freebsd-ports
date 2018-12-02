# $FreeBSD$

PORTNAME=	kiconedit
PORTVERSION=	${EXTRA_VER}
PORTREVISION=	7
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/extragear
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE icon editor

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2018-12-31

USES=		cmake gettext kde:4 qt:4 tar:bzip2
USE_KDE=	kdelibs automoc4
USE_QT=		corelib qmake_build moc_build rcc_build uic_build

EXTRA_VER=	4.4.0

post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc-translations/hu_kiconedit/kiconedit/index.docbook

.include <bsd.port.mk>

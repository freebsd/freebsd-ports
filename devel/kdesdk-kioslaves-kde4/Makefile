# $FreeBSD$

PORTNAME=	kdesdk-kioslaves
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde kde-kde4
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SDK related KIO slaves

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion

USES=		cmake kde:4 perl5 qt:4 shebangfix tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build

SHEBANG_FILES=	perldoc/pod2html.pl

.include <bsd.port.mk>

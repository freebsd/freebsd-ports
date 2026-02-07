PORTNAME=	fcitx5-hangul
DISTVERSION=	5.1.8
CATEGORIES=	korean textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Hangul support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-hangul

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libhangul.so:korean/libhangul

USES=		cmake compiler:c++17-lang gettext-tools kde:5 pkgconfig tar:zst

USE_KDE=	ecm

.include <bsd.port.mk>

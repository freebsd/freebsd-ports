# Created by: Ka Ho Ng <khng300@gmail.com>

PORTNAME=	fcitx5-table-other
DISTVERSION=	5.0.6
CATEGORIES=	chinese textproc

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Other table support for Fcitx5

LICENSE=	GPLv3

LIB_DEPENDS=	libIMETable.so:chinese/libime \
		libFcitx5Core.so:textproc/fcitx5

USES=		gettext-tools cmake kde:5

OPTIONS_DEFINE=	DEPRECATED

DEPRECATED_DESC=	Deprecated tables
DEPRECATED_CMAKE_BOOL=	ENABLE_DEPRECATED

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USE_KDE=	ecm

INSTALL_TARGET=	install

.include <bsd.port.mk>

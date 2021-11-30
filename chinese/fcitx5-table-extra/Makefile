# Created by: Ka Ho Ng <khng300@gmail.com>

PORTNAME=	fcitx5-table-extra
DISTVERSION=	5.0.6
CATEGORIES=	chinese textproc

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Extra table support for Fcitx5

LICENSE=	GPLv2+ GPLv3
LICENSE_COMB=	multi

LIB_DEPENDS=	libIMETable.so:chinese/libime \
		libFcitx5Core.so:textproc/fcitx5

USES=		gettext-tools cmake kde:5

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USE_KDE=	ecm

INSTALL_TARGET=	install

.include <bsd.port.mk>

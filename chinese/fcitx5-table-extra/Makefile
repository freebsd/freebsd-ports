# Created by: Ka Ho Ng <khng300@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx5-table-extra
DISTVERSION=	5.0.1
CATEGORIES=	chinese textproc

MAINTAINER=	khng300@gmail.com
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

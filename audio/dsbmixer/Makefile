# $FreeBSD$

PORTNAME=	dsbmixer
PORTVERSION=	0.2.6
CATEGORIES=	audio
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Tabbed GTK+ mixer for FreeBSD

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	dsbwrtsysctl:sysutils/dsbwrtsysctl

USES=		tar:tgz pkgconfig
USE_GNOME=	gtk20

OPTIONS_DEFINE=	DEVD NLS
OPTIONS_DEFAULT=DEVD
OPTIONS_SUB=	yes

NLS_USES=	gettext
DEVD_DESC=	Add new USB audio devices at runtime
NLS_MAKE_ARGS_OFF=	-DWITHOUT_GETTEXT
DEVD_MAKE_ARGS_OFF=	-DWITHOUT_DEVD

MAKE_ARGS+=	INSTALL_BACKEND="${INSTALL_PROGRAM}"

.include <bsd.port.mk>

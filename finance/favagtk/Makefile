PORTNAME=	favagtk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	finance

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Desktop application for Fava and Beancount
WWW=		https://gitlab.gnome.org/johannesjh/favagtk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-util:devel/appstream-glib \
		blueprint-compiler:devel/blueprint-compiler \
		fava:finance/fava \
		git:devel/git \
		WebKitWebDriver-6.0:www/webkit2-gtk@60
LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita
RUN_DEPENDS=	fava:finance/fava \
		WebKitWebDriver-6.0:www/webkit2-gtk@60

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig python \
		shared-mime-info
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	johannesjh
USE_GNOME=	glib20 pygobject3

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,python3,${PYTHON_CMD},1' \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>

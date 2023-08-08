PORTNAME=	gbrainy
DISTVERSION=	2.4.6
PORTEPOCH=	2
CATEGORIES=	games
MASTER_SITES=	https://gent.softcatala.org/jmas/gbrainy/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Brain teaser game and trainer
WWW=		https://live.gnome.org/gbrainy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtk-sharp30>0:x11-toolkits/gtk-sharp30 \
		itstool:textproc/itstool
RUN_DEPENDS=	bash:shells/bash

USES=		gettext gmake gnome mono pathfix pkgconfig shebangfix
USE_GNOME=	intltool

SHEBANG_FILES=	src/Clients/Classical/gbrainy.in

GNU_CONFIGURE=	yes
MAKE_ENV+=	MONO_REGISTRY_PATH=${WRKDIR}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_EXTRA_PATCHES=	${PATCHDIR}/NLS_ON-patch-Makefile.in
NLS_EXTRA_PATCHES_OFF=	${PATCHDIR}/NLS_OFF-patch-Makefile.in

.include <bsd.port.mk>

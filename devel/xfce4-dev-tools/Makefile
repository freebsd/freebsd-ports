PORTNAME=	xfce4-dev-tools
PORTVERSION=	4.20.0
CATEGORIES=	devel xfce
MASTER_SITES=	XFCE
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce development tools
WWW=		https://www.xfce.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed>0:textproc/gsed \
		meson>0:devel/meson
RUN_DEPENDS=	autoconf>=2.69:devel/autoconf \
		automake>=1.15:devel/automake \
		bash:shells/bash \
		libtoolize:devel/libtool

USES=		gmake gnome pkgconfig python:env shebangfix tar:bzip2 xfce
USE_GNOME=	glib20 libxslt
SHEBANG_FILES=	helpers/xfce-build helpers/xfce-do-release.in \
		helpers/xfce-get-translations \
		scripts/xdt-check-abi \
		scripts/xdt-gen-visibility

GNU_CONFIGURE=	yes

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>

# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	dbus-sharp
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=v
PORTEPOCH=	1
CATEGORIES=	devel gnome

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono interface to the D-BUS messaging system

LICENSE=	MIT

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs
USES=		autoreconf gmake mono pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	mono

post-patch:
# libc.so is an LD script not usable by dllmap, so we have to set a proper
# version number.
	@${REINPLACE_CMD} -e 's|libc.so.6|libc.so.7|' \
		${WRKSRC}/src/dbus-sharp.dll.config

.include <bsd.port.mk>

# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	dbus-sharp
PORTVERSION=	0.7.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://cloud.github.com/downloads/mono/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono interface to the D-BUS messaging system

LICENSE=	MIT

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_GMCS=${LOCALBASE}/bin/mcs
USES=		gmake mono pathfix pkgconfig

.include <bsd.port.options.mk>

post-patch:
.if ${OSVERSION} < 1000044
# libc.so is a symlink to the right libc.so.X
	${REINPLACE_CMD} -e 's|libc.so.6|libc.so|' \
		${WRKSRC}/src/dbus-sharp.dll.config
.else
# libc.so is an LD script not usable by dllmap, so we have to set a proper
# version number.
	${REINPLACE_CMD} -e 's|libc.so.6|libc.so.7|' \
		${WRKSRC}/src/dbus-sharp.dll.config
.endif

.include <bsd.port.mk>

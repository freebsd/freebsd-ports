PORTNAME=	dbus-sharp
PORTVERSION=	0.8.1
PORTREVISION=	1
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

.include <bsd.port.pre.mk>

.if defined(MONO_DEFAULT) && ${MONO_DEFAULT} > 6
BROKEN=		fails to build with Mono version ${MONO_DEFAULT}: Failure adding assembly dbus-sharp.dll to the cache: Strong name cannot be verified for delay-signed assembly
.endif

post-patch:
# libc.so is an LD script not usable by dllmap, so we have to set a proper
# version number.
	@${REINPLACE_CMD} -e 's|libc.so.6|libc.so.7|' \
		${WRKSRC}/src/dbus-sharp.dll.config

.include <bsd.port.post.mk>

# New ports collection makefile for:	pwlib
# Date created:		Fri Aug 22 07:11:44 GMT 2003
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pwlib
PORTVERSION=	1.9.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.voxgratia.org/releases/
DISTFILES=	pwlib-v1_9_2-src-tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A cross platform C++ library, used by OpenH323

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

WRKSRC=	${WRKDIR}/pwlib_v1_9_2

USE_BISON=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:259
WANT_SDL=	yes
USE_OPENSSL=	yes
NO_FILTER_SHLIBS=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

# if explicitely asked for, depend upon it
.if defined(WITH_SDL)
USE_SDL+=	sdl
.endif

# if explicitely disabled, do not depend upon it
.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-sdl
.endif

# if nobody cares, use it if it is installed already
.if !defined(WITHOUT_SDL) && !defined(WITH_SDL)
.if ${HAVE_SDL:Msdl}
USE_SDL+=       sdl
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif
.endif

.if !defined(WITHOUT_PLUGINS)
CONFIGURE_ARGS+=	--enable-plugins
.endif

#disable OpenLDAP support in PWLIB
.if defined(WITHOUT_LDAP)
CONFIGURE_ARGS+=	--disable-openldap
.else
USE_OPENLDAP=	yes
.endif

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" SDLLIBDIR="${LOCALBASE}/lib"
MAKE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" SDLLIBDIR="${LOCALBASE}/lib" STDCCFLAGS+="-I${LOCALBASE}"

#.if ${OSVERSION} < 502101
#ONLY_FOR_ARCHS=	i386
#.endif

.include <bsd.port.post.mk>

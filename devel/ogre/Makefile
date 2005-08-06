# New ports collection makefile for:	ogre
# Date created:				2005 Jul 10
# Whom:					Jack Twilley <jmt@twilley.org>
#
# $FreeBSD$
#

PORTNAME=	ogre
DISTVERSION=	1.0.3p1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ogre
DISTNAME=	ogre-linux_osx-v1-0-3p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-Oriented Graphical Rendering Engine

BUILD_DEPENDS=	${LOCALBASE}/lib/libzzip.a:${PORTSDIR}/devel/zziplib \
		${LOCALBASE}/bin/sdl11-config:${PORTSDIR}/devel/sdl12 \
		${LOCALBASE}/lib/libIL.a:${PORTSDIR}/graphics/devil \
		${LOCALBASE}/lib/libcppunit.a:${PORTSDIR}/devel/cppunit

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ogrenew

USE_AUTOMAKE_VER=	19
AUTOMAKE_ARGS=	--include-deps --add-missing --foreign
USE_AUTOCONF_VER=	259
USE_ACLOCAL_VER=	19
ACLOCAL_ARGS=	-I Scripts/m4 -I ${LOCALBASE}/share/aclocal
USE_LIBTOOL_VER=	15

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cg
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lc" SDL_CONFIG=${LOCALBASE}/bin/sdl11-config
INSTALLS_SHLIB=	yes
PLIST_SUB+=	CONFIGURE_TARGET="${CONFIGURE_TARGET}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not compile"
.endif

post-patch:
	@${RM} -rf ${WRKSRC}/autom4te.cache

pre-configure:
	@(${SED} -i.orig -e 's,[(]libdir[)],(prefix)/libdata,' ${WRKSRC}/Makefile.am)
	@(${FIND} ${WRKSRC} -type f -name Makefile.am -print0 | ${XARGS} -0 ${SED} -i.orig -e 's#.libs/##')
	@(cd ${WRKSRC} && ${LIBTOOLIZE} --copy --force && ${SED} -i.orig -e '/X-lc.*continue/d' ltmain.sh)

pre-build:
	@(${FIND} ${WRKSRC} -type d -name obj -print0 | ${XARGS} -0 ${RM} -rf)

.include <bsd.port.post.mk>

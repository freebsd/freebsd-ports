# New ports collection makefile for:	fileroller
# Date created:				18 May 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fileroller
PORTVERSION=	2.2.1
PORTEPOCH=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/file-roller/2.2
DISTNAME=	file-roller-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui
RUN_DEPENDS=	bzip:${PORTSDIR}/archivers/bzip \
		lha:${PORTSDIR}/archivers/lha \
		lzop:${PORTSDIR}/archivers/lzop


USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_RAR) || exists(${LOCALBASE}/bin/rar)
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

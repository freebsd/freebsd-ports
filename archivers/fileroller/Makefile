# New ports collection makefile for:	fileroller
# Date created:				18 May 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fileroller
PORTVERSION=	2.4.2
PORTEPOCH=	1
CATEGORIES=	archivers gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/file-roller/2.4
DISTNAME=	file-roller-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An archive manager for zip files, tar, etc

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		lzop:${PORTSDIR}/archivers/lzop \
		zoo:${PORTSDIR}/archivers/zoo
.if !exists(/usr/bin/bzip2)
RUN_DEPENDS+=	bzip2:${PORTSDIR}/archivers/bzip2
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_RAR) || exists(${LOCALBASE}/bin/rar)
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
.endif

.if defined(WITH_BZIP) || exists(${LOCALBASE}/bin/bzip)
RUN_DEPENDS+=	bzip:${PORTSDIR}/archivers/bzip
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

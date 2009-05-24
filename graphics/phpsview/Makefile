# New ports collection makefile for:	phpsview
# Date created:				17 April 2005
# Whom:					Yoshihiko Sarumaru <mistral@imasy.or.jp>
#
# $FreeBSD$
#

PORTNAME=	phpsview
PORTVERSION=	10.0.5
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.saillard.org/linux/pwc/old-releases/
DISTNAME=	${REALNAME}-${PORTVERSION}

PATCH_SITES=	http://vinvin.dyndns.org/projects/
PATCHFILES=	${REALNAME}-${PORTVERSION}-bsd-0.06.patch.gz
PATCH_DIST_STRIP=       -p1

MAINTAINER=	sarumaru@jp.FreeBSD.org
COMMENT=	Philips USB Cameras Utilities for NetBSD/FreeBSD

REALNAME=	pwc

USE_BZIP2=	yes

.if defined(WITHOUT_X11)
COMPONENTS=	phpsshot
.else
USE_GNOME=	imlib gtk12
COMPONENTS=	phpsshot phpsview
.endif

MAN1=		${COMPONENTS:S/$/.1/}
MANCOMPRESSED=	yes
PLIST_FILES=	${COMPONENTS:S/^/bin\//}

MAKE_ARGS+=	MANDIR=${MANPREFIX}/man/man

do-build:
.for component in ${COMPONENTS}
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} Makefile.${component} ${MAKE_ARGS} ${ALL_TARGET})
.endfor

do-install:
.for component in ${COMPONENTS}
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} Makefile.${component} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	yudit
# Date created:		October 3, 1998
# Whom:			rch@richard.eu.org
#
# $FreeBSD$
#

PORTNAME=	yudit
PORTVERSION=	1.6
CATEGORIES=	editors converters print
MASTER_SITES=	http://yudit.org/download/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= apps/editors/X
DISTNAME=	${PORTNAME}-1.6

PATCH_SITES=	http://yudit.org/download/
#PATCHFILES=	yudit-1.5.patch1
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	rch@WriteMe.Com

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_FREETYPE=	YES
USE_XLIB=	YES
CONFIGURE_ENV=	LC_ALL=
GNU_CONFIGURE=	YES
MAKE_ENV=	LC_ALL=
MAN1=		yudit.1 makeumap.1 stripumap.1 uniconv.1 uniprint.1
USE_GMAKE=	YES

pre-patch:
	@${PERL} -pi.orig -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/UFontMap.cpp

post-install:
	cd ${PREFIX}/bin/ && strip yudit stripumap uniconv uniprint

.include <bsd.port.mk>

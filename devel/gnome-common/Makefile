# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-common
PORTVERSION=	3.14.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for GNOME 3

BUILD_DEPENDS=	autoconf-archive>=0:${PORTSDIR}/devel/autoconf-archive

USES=		gmake pkgconfig tar:xz
GNU_CONFIGURE=	yes

# remove files provided by autoconf-archive
post-install:
	@${RM} ${STAGEDIR}${PREFIX}/share/aclocal/ax_check_enable_debug.m4
	@${RM} ${STAGEDIR}${PREFIX}/share/aclocal/ax_code_coverage.m4

.include <bsd.port.mk>

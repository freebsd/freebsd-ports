# New ports collection makefile for:	libaudiofile
# Date created:				22 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libaudiofile
PORTVERSION=	0.2.3
CATEGORIES=	audio
MASTER_SITES=	ftp://oss.sgi.com/projects/audiofile/download/ \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/audiofile/0.2
DISTNAME=	audiofile-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

.include <bsd.port.mk>

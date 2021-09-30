# Created by: Piotr Kubaj <pkubaj@anongoth.pl>

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.11
DISTVERSIONSUFFIX=	-6.el7
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL7/s
DISTNAME=	SDL_ttf-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load True Type Fonts as SDL interfaces (Linux CentOS ${LINUX_DIST_VER})

ONLY_FOR_ARCHS=	aarch64 amd64

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	jpeg png sdl12 tiff
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL_ttf-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

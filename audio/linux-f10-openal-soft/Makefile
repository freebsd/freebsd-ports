# Created by: mva
# $FreeBSD: head/audio/linux-f10-openal-soft/Makefile 362027 2014-07-16 03:47:05Z adamw $

PORTNAME=	openal-soft
PORTVERSION=	1.8.466
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}.fc10

MAINTAINER=	mva@FreeBSD.org
COMMENT=	3D positional spatialized sound library (Linux Fedora 10)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	alsalib arts esound
LINUX_DIST_VER=	10
RPMVERSION=	7
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libopenal.so.1 usr/lib/libopenal.so.${PORTVERSION} \
		usr/bin/openal-info
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	COPYING
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>

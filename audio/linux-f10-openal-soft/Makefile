# Created by: mva
# $FreeBSD$

PORTNAME=	openal-soft
PORTVERSION=	1.8.466
PORTREVISION=	1
CATEGORIES=	audio linux

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A 3D positional spatialized sound library (Linux Fedora 10)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	alsalib arts esound

RPMVERSION=	7.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libopenal.so.1 usr/lib/libopenal.so.${PORTVERSION} \
		usr/bin/openal-info
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	COPYING
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

# Created by: Mark Kane <mark@mkproductions.org>
# $FreeBSD$

PORTNAME=	xarchive
DISTVERSION=	0.2.8-6
PORTREVISION=	8
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	mark@mkproductions.org
COMMENT=	GTK+ front end for various archiving tools

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

OPTIONS_DEFINE=	7ZIP ARJ ACE DEB RAR RPM ZIP

7ZIP_DESC=	7zip archive support
ARJ_DESC=	ARJ archive support
ACE_DESC=	ACE archive support
DEB_DESC=	DEB archive support
RAR_DESC=	RAR archive support
RPM_DESC=	RPM archive support
ZIP_DESC=	ZIP archive support

7ZIP_RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip
ARJ_RUN_DEPENDS=	arj:${PORTSDIR}/archivers/arj
ACE_RUN_DEPENDS=	unace:${PORTSDIR}/archivers/unace
DEB_RUN_DEPENDS=	dpkg-deb:${PORTSDIR}/archivers/dpkg
RAR_RUN_DEPENDS=	rar:${PORTSDIR}/archivers/rar \
		unrar:${PORTSDIR}/archivers/unrar
RPM_RUN_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio \
		rpm:${PORTSDIR}/archivers/rpm4
ZIP_RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip

.include <bsd.port.mk>

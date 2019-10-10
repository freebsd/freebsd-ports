# Created by: Mark Kane <mark@mkproductions.org>
# $FreeBSD$

PORTNAME=	xarchive
DISTVERSION=	0.2.8-6
PORTREVISION=	9
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	mark@mkproductions.org
COMMENT=	GTK+ front end for various archiving tools

RUN_DEPENDS=	bash:shells/bash

USES=		gnome pkgconfig
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

7ZIP_RUN_DEPENDS=	7z:archivers/p7zip
ARJ_RUN_DEPENDS=	arj:archivers/arj
ACE_RUN_DEPENDS=	unace:archivers/unace
DEB_RUN_DEPENDS=	dpkg-deb:archivers/dpkg
RAR_RUN_DEPENDS=	rar:archivers/rar \
		unrar:archivers/unrar
RPM_RUN_DEPENDS=	rpm2cpio:archivers/rpm2cpio \
		rpm:archivers/rpm4
ZIP_RUN_DEPENDS=	zip:archivers/zip

.include <bsd.port.mk>

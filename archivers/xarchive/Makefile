# Created by: Mark Kane <mark@mkproductions.org>
# $FreeBSD$

PORTNAME=	xarchive
DISTVERSION=	0.2.8-6
PORTREVISION=	7
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	mark@mkproductions.org
COMMENT=	GTK+ front end for various archiving tools

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	7ZIP ARJ ACE DEB RAR RPM ZIP

7ZIP_DESC=	7zip archive support
ARJ_DESC=	ARJ archive support
ACE_DESC=	ACE archive support
DEB_DESC=	DEB archive support
RAR_DESC=	RAR archive support
RPM_DESC=	RPM archive support
ZIP_DESC=	ZIP archive support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M7ZIP}
RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
.endif

.if ${PORT_OPTIONS:MARJ}
RUN_DEPENDS+=	arj:${PORTSDIR}/archivers/arj
.endif

.if ${PORT_OPTIONS:MACE}
RUN_DEPENDS+=	unace:${PORTSDIR}/archivers/unace
.endif

.if ${PORT_OPTIONS:MDEB}
RUN_DEPENDS+=	dpkg-deb:${PORTSDIR}/archivers/dpkg
.endif

.if ${PORT_OPTIONS:MRAR}
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar \
		unrar:${PORTSDIR}/archivers/unrar
.endif

.if ${PORT_OPTIONS:MRPM}
RUN_DEPENDS+=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio \
		rpm:${PORTSDIR}/archivers/rpm
.endif

.if ${PORT_OPTIONS:MZIP}
RUN_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
.endif

.include <bsd.port.mk>

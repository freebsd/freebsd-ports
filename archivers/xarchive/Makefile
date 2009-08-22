# New ports collection makefile for:	xarchive
# Date created:				09 November 2005
# Whom:					Mark Kane <mark@mkproductions.org>
#
# $FreeBSD$
#

PORTNAME=	xarchive
PORTVERSION=	0.2.8.6
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.2.8-6
DISTNAME=	${PORTNAME}-0.2.8-6

MAINTAINER=	mark@mkproductions.org
COMMENT=	A GTK+ front end for archiving tools

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

MAN1=		xarchive.1

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

OPTIONS=	7ZIP "Support for 7zip archives" off \
		ARJ "Support for ARJ archives" off \
		ACE "Support for ACE archives" off \
		DEB "Support for DEB archives" off \
		RAR "Support for RAR archives" off \
		RPM "Support for RPM archives" off \
		ZIP "Support for ZIP archives" off

.include <bsd.port.pre.mk>

.if defined (WITH_7ZIP)
RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip
.endif

.if defined (WITH_ARJ)
RUN_DEPENDS+=	arj:${PORTSDIR}/archivers/arj
.endif

.if defined (WITH_ACE)
RUN_DEPENDS+=	unace:${PORTSDIR}/archivers/unace
.endif

.if defined (WITH_DEB)
RUN_DEPENDS+=	dpkg-deb:${PORTSDIR}/archivers/dpkg
.endif

.if defined (WITH_RAR)
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar \
		unrar:${PORTSDIR}/archivers/unrar
.endif

.if defined (WITH_RPM)
RUN_DEPENDS+=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio \
		rpm:${PORTSDIR}/archivers/rpm
.endif

.if defined (WITH_ZIP)
RUN_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
.endif

.include <bsd.port.post.mk>

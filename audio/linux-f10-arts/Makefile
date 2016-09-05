# Created by: bsam
# $FreeBSD$

PORTNAME=		arts
PORTVERSION=		1.5.10
PORTREVISION=		1
CATEGORIES=		audio kde linux

MAINTAINER=		emulation@FreeBSD.org
COMMENT=		Audio system for the KDE integrated X11 desktop (Linux Fedora 10)

CONFLICTS=		linux-arts-[0-9]* linux-f8-arts-[0-9]*

USES=			linux:f10
USE_LINUX_RPM=		yes

RPMVERSION=		1.fc10
USE_LDCONFIG=		yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/usr/lib/*.la

.include <bsd.port.mk>

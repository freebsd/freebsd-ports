# New ports collection makefile for:	lang/linux-f10-tcl85
# Date created:				2009-05-04
# Whom:					bsam
# $FreeBSD$
#

PORTNAME=	tcl
PORTVERSION=	8.5.3
CATEGORIES=	lang linux
PKGNAMEPREFIX=	linux-f10-
PKGNAMESUFFIX=	85
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool Command Language (Linux Fedora 10)

CONFLICTS=	linux-f8-tcl84-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
BRANDELF_FILES=	usr/bin/tclsh8.5
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>

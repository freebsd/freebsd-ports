# New ports collection makefile for:    lang/linux-f8-tcl84
# Date created:                         21 January 2009
# Whom:                                 Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$
#

PORTNAME=	tcl
PORTVERSION=	8.4.17
PORTREVISION=	1
CATEGORIES=	lang linux
PKGNAMEPREFIX=	linux-f8-
PKGNAMESUFFIX=	84
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Tool Command Language (Linux Fedora 8)

CONFLICTS=	linux-f10-tcl85-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	1.fc8
BRANDELF_FILES=	usr/bin/tclsh8.4
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION="${PORTVERSION}"
DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION}<700055
	IGNORE=		You need at least FreeBSD>=7.0 RELEASE with Linux emulation 2.6.x
.endif

.include <bsd.port.post.mk>

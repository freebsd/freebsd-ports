# New ports collection makefile for:	accessibility/linux-f8-atk
# Date created:				2008-03-29
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	atk
PORTVERSION=	1.20.0
PORTREVISION=	1
CATEGORIES=	accessibility linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Accessibility Toolkit, Linux/i386 binary (Linux Fedora 8)

CONFLICTS=	linux-atk-[0-9]* linux-f10-atk-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	1.fc8
USE_LDCONFIG=	yes

.include <bsd.port.mk>

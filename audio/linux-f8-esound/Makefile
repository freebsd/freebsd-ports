# New ports collection makefile for:	audio/linux-f8-esound
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	esound
PORTVERSION=	0.2.38
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of esound (Linux Fedora 8)

CONFLICTS=	linux-esound-[0-9]* linux-f10-esound-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libaudiofile
LINUX_NAME=	${PORTNAME}-libs
LINUX_DIST_VER=	8
RPMVERSION=	6.fc8
USE_LDCONFIG=	yes
SRC_DISTFILES=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}${SRC_SUFX}

PLIST_FILES=	etc/esd.conf usr/lib/libesd.so.0 usr/lib/libesd.so.0.2.38 \
		usr/lib/libesddsp.so.0 usr/lib/libesddsp.so.0.2.38
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING.LIB ChangeLog NEWS README TIPS TODO esound.sgml
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>

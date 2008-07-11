# New ports collection makefile for:	msynctool
# Date created:				11 July 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	msynctool
PORTVERSION=	0.22
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	ports@logvinov.com
COMMENT=	A command line client for the OpenSync framework

LIB_DEPENDS=	opensync.0:${PORTSDIR}/devel/libopensync022

CONFLICTS=	msynctool-devel-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		convcard.1 ${PORTNAME}.1

PLIST_FILES=	bin/convtest \
		bin/convcard \
		bin/${PORTNAME}

.include <bsd.port.mk>

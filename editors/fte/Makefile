# New ports collection makefile for:	fte
# Date created:				8 May 2000
# Whom:					gelf
#
# $FreeBSD$
#

PORTNAME=		fte
PORTVERSION=		20020324
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=		${PORTNAME}-${PORTVERSION:S/./b/}-src.zip \
			${PORTNAME}-${PORTVERSION:S/./b/}-common.zip

MAINTAINER=		mail@gelf.com
COMMENT=		A full-featured text editor for X11

BUILD_DEPENDS=  	unzip:${PORTSDIR}/archivers/unzip

WRKSRC=			${WRKDIR}/fte

EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=
USE_XLIB=		yes
USE_ZIP=		yes

.include <bsd.port.mk>

# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	osynctool
PORTVERSION=	0.39
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/ \
		LOCAL/danilo

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Command line client for the OpenSync framework

LIB_DEPENDS=	libopensync.so:devel/libopensync

CONFLICTS=	msynctool-0.2*

USES=		cmake:outsource pkgconfig tar:bzip2

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/${PORTNAME}.sh

.include <bsd.port.mk>

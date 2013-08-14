# New ports collection makefile for:	librtfcomp
# Date Created:				13 June 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	librtfcomp
PORTVERSION=	1.1
CATEGORIES?=	archivers
MASTER_SITES=	SF/synce/SynCE/0.10.0

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	LZRTF compression library


USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(RTFCOMP_SLAVE) && ${RTFCOMP_SLAVE} == "pythonb"
CONFIGURE_ARGS=	--enable-python-bindings
.else
CONFIGURE_ARGS=	--disable-python-bindings
.endif

.include <bsd.port.post.mk>

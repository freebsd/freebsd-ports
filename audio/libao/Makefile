# New ports collection makefile for:	libao
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libao
PORTVERSION=	0.7.0
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc1/unix/

MAINTAINER=	naddy@mips.inka.de

WANT_ESOUND=	yes

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

.include <bsd.port.pre.mk>

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
PLIST_SUB=	ESOUND=""
.else
PLIST_SUB=	ESOUND="@comment "
.endif

.if exists(${LOCALBASE}/bin/artsc-config)
LIB_DEPENDS=	artsc.0:${PORTSDIR}/x11/kdelibs2
PLIST_SUB+=	ARTS=""
.else
PLIST_SUB+=	ARTS="@comment "
.endif

.include <bsd.port.post.mk>

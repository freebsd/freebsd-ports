# New ports collection makefile for:	libogg
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libogg
PORTVERSION=	1.1
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/1.0.1/unix/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Ogg bitstream library

USE_LIBTOOL_VER=	13
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

.include <bsd.port.mk>

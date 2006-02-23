# New ports collection makefile for:	libogg
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libogg
PORTVERSION=	1.1.3
PORTEPOCH=	3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/ogg/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Ogg bitstream library

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	DOC=""
.else
MAKE_ENV=	DOC=doc
.endif

.include <bsd.port.mk>

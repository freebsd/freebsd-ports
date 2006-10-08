# New ports collection makefile for:	eet
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	eet
PORTVERSION=	20060926
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment Data Handling Library

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502126
IGNORE=		freebsd 3.*, 4.*, 5.0, 5.1 are not supported
.endif

.include <bsd.port.post.mk>

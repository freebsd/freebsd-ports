# New ports collection makefile for:	edje
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	edje
PORTVERSION=	20070223
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Edje is a complex graphical design and layout engine

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GCC=	3.4
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	embryo eet evas ecore imlib2
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not build on 4.X
.endif

.if ${ARCH} == "ia64"
BROKEN=		edje is broken on ia64
.endif

.include <bsd.port.post.mk>

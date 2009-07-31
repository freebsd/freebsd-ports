# New ports collection makefile for:	edje
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	edje
PORTVERSION=	0.5.0.042
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Edje is a complex graphical design and layout engine

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	embryo eet evas ecore imlib2
USE_EFL_ECORE=	evas job
USE_EVAS_LOADERS=	edb eet jpeg png
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--without-vim

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		edje is broken on ia64
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	imlib2_loaders
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2_loaders
PORTVERSION=	1.4.1.000
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget
USE_EFL=	edb eet imlib2

OPTIONS=	EDB	"Enable edb loader" on \
		EET	"Enable eet loader" on \
		XCF	"Enable XCF loader" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EDB)
USE_EFL+=	edb
PLIST_SUB+=	EDB=""
.else
CONFIGURE_ARGS+=	--disable-edb
PLIST_SUB+=	EDB="@comment "
.endif

.if !defined(WITHOUT_EET)
USE_EFL+=	eet
PLIST_SUB+=	EET=""
.else
CONFIGURE_ARGS+=	--disable-eet
PLIST_SUB+=	EET="@comment "
.endif

.if !defined(WITHOUT_XCF)
PLIST_SUB+=	XCF=""
.else
CONFIGURE_ARGS+=	--disable-xcf
PLIST_SUB+=	XCF="@comment "
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	imlib2_loaders
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	imlib2_loaders
PORTVERSION=	20060926
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Extra image loader plugins for Imlib 2

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2 \
		edb.1:${PORTSDIR}/databases/edb \
		eet.9:${PORTSDIR}/devel/eet

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget

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

.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>

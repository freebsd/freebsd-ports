# Ports collection makefile for:  wormux-devel
# Date created:			  21 November 2006
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wormux
DISTVERSION=	0.8
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/wormux/
PKGNAMESUFFIX=	-devel
DISTNAME=	wormux-${PORTVERSION}alpha1

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Wormux game

LIB_DEPENDS=	xml\\+\\+-2.6.2:${PORTSDIR}/textproc/libxml++26

GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer ttf gfx net
USE_BZIP2=	yes

CONFIGURE_ARGS=	--with-datadir-name=${DATADIR} --program-prefix=""

MAN6=	wormux.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>

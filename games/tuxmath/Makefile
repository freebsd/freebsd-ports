# New ports collection makefile for:	tuxmath
# Date created:				14 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxmath
PORTVERSION=	1.6.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	http://alioth.debian.org/frs/download.php/2191/
DISTNAME=	${PORTNAME}_w_fonts-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Educational arcade game starring Tux

USE_GMAKE=	yes
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
WRKSRC=		${WRKDIR}/${DISTNAME:S/${PORTVERSION}/1.5.8/}

OPTIONS=	NLS "Enable Native Language Support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(prefix)/doc/$$(PACKAGE)|$$(docdir)|' \
		${WRKSRC}/docs/Makefile.in

.include <bsd.port.post.mk>

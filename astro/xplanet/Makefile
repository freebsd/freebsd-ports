# New ports collection makefile for:    xplanet
# Date created:		22 Feb 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

PORTNAME=	xplanet
PORTVERSION=	0.60
CATEGORIES=	astro x11
MASTER_SITES=	ftp://ftp.sourceforge.net/pub/sourceforge/xplanet/ \
		http://www.radcyberzine.com/xglobe/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} photo_1600.jpg

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		GL.14:${PORTSDIR}/graphics/Mesa3

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-map-extension=jpg
MAN1=		xplanet.1 xplanetbg.1

.include <bsd.port.pre.mk>

.if (!defined(WITH_TK80) && !defined(WITH_TK81) && !defined(WITH_TK82) && !defined(WITH_TK83))
.if exists(${LOCALBASE}/bin/wish8.3)
WITH_TK83=      yes
.elif exists(${LOCALBASE}/bin/wish8.2)
WITH_TK82=	yes
.elif exists(${LOCALBASE}/bin/wish8.1)
WITH_TK81=      yes
.else
WITH_TK80=	yes
.endif
.endif

.if defined(WITH_TK80)
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80
WISH=		${LOCALBASE}/bin/wish8.0
TKVERMSG=	"Using Tk 8.0"
.endif

.if defined(WITH_TK81)
RUN_DEPENDS=	wish8.1:${PORTSDIR}/x11-toolkits/tk81
WISH=		${LOCALBASE}/bin/wish8.1
TKVERMSG=	"Using Tk 8.1"
.endif

.if defined(WITH_TK82)
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82
WISH=		${LOCALBASE}/bin/wish8.2
TKVERMSG=	"Using Tk 8.2"
.endif

.if defined(WITH_TK83)
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
WISH=		${LOCALBASE}/bin/wish8.3
TKVERMSG=	"Using Tk 8.3"
.endif

CONFIGURE_ENV+=	WISH=${WISH}

pre-fetch:
	@${ECHO} ${TKVERMSG}
	@${ECHO} "Define WITH_TK80, WITH_TK81, WITH_TK82, or WITH_TK83"
	@${ECHO} "To use a different version of TK"

pre-configure:
	@${PERL} -pi -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure

pre-build:
	@${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/auxfiles.h

post-install:
	@${INSTALL_DATA} ${DISTDIR}/photo_1600.jpg ${PREFIX}/share/xplanet/earth.jpg

.include <bsd.port.post.mk>

# New ports collection makefile for:    xplanet
# Version required:	0.50
# Date created:		22 Feb 2000
# Whom:			darius@dons.net.au
#
# $FreeBSD$
#

DISTNAME=	xplanet-0.50
CATEGORIES=	astro x11
MASTER_SITES=	http://www.alumni.caltech.edu/~hari/xplanet/ \
		http://www.radcyberzine.com/xglobe/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} photo_1600.jpg

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		GL.14:${PORTSDIR}/graphics/Mesa3

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-map-extension=jpg
MAN1=		xplanet.1 xplanetbg.1

.include <bsd.port.pre.mk>

.if (!defined(USE_TK80) && !defined(USE_TK81) && !defined(USE_TK82) && !defined(USE_TK83))
.if exists(${LOCALBASE}/bin/wish8.3)
USE_TK83=      yes
.elif exists(${LOCALBASE}/bin/wish8.2)
USE_TK82=	yes
.elif exists(${LOCALBASE}/bin/wish8.1)
USE_TK81=      yes
.else
USE_TK80=	yes
.endif
.endif

.if defined(USE_TK80)
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80
WISH=		${LOCALBASE}/bin/wish8.0
TKVERMSG=	"Using Tk 8.0"
.endif

.if defined(USE_TK81)
RUN_DEPENDS=	wish8.1:${PORTSDIR}/x11-toolkits/tk81
WISH=		${LOCALBASE}/bin/wish8.1
TKVERMSG=	"Using Tk 8.1"
.endif

.if defined(USE_TK82)
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82
WISH=		${LOCALBASE}/bin/wish8.2
TKVERMSG=	"Using Tk 8.2"
.endif

.if defined(USE_TK83)
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
WISH=		${LOCALBASE}/bin/wish8.3
TKVERMSG=	"Using Tk 8.3"
.endif

CONFIGURE_ENV+=	WISH=${WISH}

pre-fetch:
	@${ECHO} ${TKVERMSG}
	@${ECHO} "Define USE_TK80, USE_TK81, USE_TK82, or USE_Tk83"
	@${ECHO} "To use a different version of TK"

pre-configure:
	@${PERL} -pi -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure

pre-build:
	@${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/auxfiles.h

post-install:
	@${INSTALL_DATA} ${DISTDIR}/photo_1600.jpg ${PREFIX}/share/xplanet/earth.jpg

.include <bsd.port.post.mk>

# New ports collection makefile for:	Swami
# Date created:			25 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	swami
PORTVERSION=	0.9.4
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An advanced instrument editor

LIB_DEPENDS=	fluidsynth.4:${PORTSDIR}/audio/fluidsynth \
		audiofile.0:${PORTSDIR}/audio/libaudiofile \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		popt.0:${PORTSDIR}/devel/popt \
		png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk12
WANT_GNOME=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomelibs}!=""
USE_GNOME+=	gnomelibs
.else
CONFIGURE_ARGS=	--disable-gnome-canvas
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-g $${CFLAGS}|$${CFLAGS}|g ; \
		 s|libpng|libpng14|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

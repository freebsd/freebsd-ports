# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Media player for KDE

LIB_DEPENDS=	artsgui:${PORTSDIR}/multimedia/kdemultimedia3

.if defined(WITH_GSTREAMER)
LIB_DEPENDS+=	gstplay-0.8.1:${PORTSDIR}/multimedia/gstreamer-plugins
.else
CONFIGURE_ARGS=	--without-gstreamer
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=--without-opengl
.endif

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

pre-everything::
.if !defined(WITH_GSTREAMER)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITH_GSTREAMER to enable experimental GStreamer support'
.endif
.if !defined(WITHOUT_OPENGL)
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===> Define WITHOUT_OPENGL to disable OpenGL support'
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>

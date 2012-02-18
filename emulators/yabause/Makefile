# New ports collection makefile for:	yabause
# Date created:		2006-08-23
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yabause
PORTVERSION=	0.9.10
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Sega Saturn system emulator

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		gl glu glut
USE_GNOME=	#
USE_OPENAL=	soft
USE_QT_VER=	4
USE_SDL=	yes

SUB_FILES=	pkg-message
MAN1=	yabause.1

OPTIONS=	QT4	"Build wit qt4 interface instead of gtk2 one"	on

.include <bsd.port.pre.mk>

.if defined(WITH_QT4)
QT_COMPONENTS=	corelib gui opengl
CONFIGURE_ARGS+=	--with-port=qt
.else
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	--with-port=gtk
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>

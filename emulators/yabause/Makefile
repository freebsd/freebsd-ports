# New ports collection makefile for:	yabause
# Date created:		2006-08-23
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yabause
PORTVERSION=	0.9.11.1
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:S/1.1/1/g}/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Sega Saturn system emulator

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_AUTOTOOLS=	automake:env autoconf:env aclocal:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		gl glu glut
USE_GNOME=	#
USE_OPENAL=	soft
USE_SDL=	yes

SUB_FILES=	pkg-message
MAN1=	yabause.1

OPTIONS=	QT4	"Build wit qt4 interface instead of gtk2 one"	on

.include <bsd.port.options.mk>

.if defined(WITH_QT4)
USE_QT4=	corelib gui opengl
CONFIGURE_ARGS+=	--with-port=qt
.else
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	--with-port=gtk
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|%%ACLOCAL%%|${ACLOCAL}|g" -e "s|%%AUTOCONF%%|${AUTOCONF}|g" \
		-e "s|%%AUTOMAKE%%|${AUTOMAKE}|g" ${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -e "s|0.9.10|${PORTVERSION}|g" ${WRKSRC}/configure.in

pre-configure:
	@cd ${WRKSRC} && ${SH} autogen.sh

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>

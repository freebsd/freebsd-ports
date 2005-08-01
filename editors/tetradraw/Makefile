# ex:ts=8
# Ports collection makefile for:	tetradraw
# Date created:			1 October 2002
# Whom:				Frederic Cambus
#
# $FreeBSD$
#

PORTNAME=	tetradraw
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fully featured ANSI art editor/viewer with TCP/IP multidraw support

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/tetradraw bin/tetraview

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS =.*$$|CFLAGS = @CFLAGS@|g' ${WRKSRC}/src/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

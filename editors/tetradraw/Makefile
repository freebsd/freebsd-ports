# Created by: Frederic Cambus
# $FreeBSD$

PORTNAME=	tetradraw
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fully featured ANSI art editor/viewer with TCP/IP multidraw support

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tetradraw bin/tetraview

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS =.*$$|CFLAGS = @CFLAGS@|g' ${WRKSRC}/src/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

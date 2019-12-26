# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gpaint
PORTVERSION=	0.3.3
DISTVERSIONPREFIX=	2-
PORTREVISION=	7
CATEGORIES=	graphics gnome
MASTER_SITES=	GNU_ALPHA

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small-scale painting program for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pkgconfig
USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes
LIBS+=		-lm

PLIST_FILES=	bin/gpaint-2 %%DATADIR%%/glade/gpaint.glade

post-patch:
	@${REINPLACE_CMD} -e \
		's|_RESPONSE_DISCARD|_RESPONSE_NO|g' ${WRKSRC}/src/drawing.c

.include <bsd.port.mk>

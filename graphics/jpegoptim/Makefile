# New ports collection makefile for:	DirectFB
# Date created:				24 January 2003
# Whom:					Devaux Fabien <fab@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	jpegoptim
PORTVERSION=	1.2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to optimize jpeg files

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libjpeg=${LOCALBASE}

MAN1=		jpegoptim.1
PLIST_FILES=	bin/jpegoptim

post-patch:
	@${REINPLACE_CMD} -e \
		's|^bindir =.*$$|bindir = @bindir@|g ; \
		 s|^mandir =.*$$|mandir = @mandir@|g ; \
		 s|$$(INSTALL) -m 755|$$(INSTALL_PROGRAM)|g ; \
	         s|$$(INSTALL) -m 644|$$(INSTALL_DATA)|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

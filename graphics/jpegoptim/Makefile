# Created by: Devaux Fabien <fab@gcu.info>
# $FreeBSD$

PORTNAME=	jpegoptim
PORTVERSION=	1.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Utility to optimize jpeg files

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libjpeg=${LOCALBASE}

PLIST_FILES=	bin/jpegoptim man/man1/jpegoptim.1.gz

MAKE_ENV+=	INSTALL_ROOT=${STAGEDIR}

post-patch:
	@${REINPLACE_CMD} -e \
		's|^bindir =.*$$|bindir = @bindir@|g ; \
		 s|^mandir =.*$$|mandir = @mandir@|g ; \
		 s|$$(INSTALL) -m 755|$$(INSTALL_PROGRAM)|g ; \
	         s|$$(INSTALL) -m 644|$$(INSTALL_DATA)|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

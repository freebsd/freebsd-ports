# Created by: Sheldon Hearn <axl@iafrica.com>
# $FreeBSD$

PORTNAME=	xzx
PORTVERSION=	4.6
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	http://fossies.org/linux/misc/
DISTNAME=	${PORTNAME}-pro-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ZX Spectrum (48K/128K/+3) Emulator for X11

BROKEN=		Unfetchable

USES=		imake:env motif

USE_XORG=	x11 ice sm xext xpm xt xxf86vm

# License forbids redistribution
RESTRICTED=	Redistribution forbidden by license

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-oss

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-pro

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${REINPLACE_CMD} 's,(pkglibdir),(datadir)/doc/@PACKAGE@,' ${WRKSRC}/doc/Makefile.in

# Prevent configure from trying to run auto* since it's not needed and will
# error if auto* < 2.54
post-configure:
		@${REINPLACE_CMD} 's@autoheader@${TRUE}@g' ${WRKSRC}/Makefile
		@${REINPLACE_CMD} 's@autoconf@${TRUE}@g' ${WRKSRC}/Makefile
		@${ECHO_CMD} "${TRUE}" > ${WRKSRC}/missing

.include <bsd.port.mk>

# New ports collection makefile for:	mtpaint
# Date created:		3 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mtpaint
PORTVERSION=	3.11
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Simple painting program

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
HAS_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MAN1PREFIX}/man/man1 \
		--locale=${PREFIX}/share/locale gif jpeg tiff slow \
		gtk2 intl man
MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-o /dev/null|-o `mktemp -t /tmp`|' ${WRKSRC}/configure

.include <bsd.port.mk>

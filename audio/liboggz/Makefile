# New ports collection makefile for:	liboggz
# Date created:		08 October 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liboggz
DISTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/liboggz//

MAINTAINER=	jsa@wickedmachine.net
COMMENT=	Simple Ogg API

LIB_DEPENDS=	ogg.6:${PORTSDIR}/audio/libogg

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE} --program-transform-name=""
CONFIGURE_ENV=	HAVE_DOCBOOK2HTML=false DOCBOOKTOMAN=false HAVE_DOXYGEN=false HAVE_VALGRIND=false

post-patch:
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s!=.*!= ${PREFIX}/libdata/pkgconfig!' ${WRKSRC}/Makefile.in
.ifdef NOPORTDOCS
	@${REINPLACE_CMD} -e '/^install-data-am/s!install-data-local!!' ${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>

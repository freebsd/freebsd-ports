# New ports collection makefile for:	freesci
# Date created:				17 December 2000
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		freesci
PORTVERSION=		0.3.0
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.linuxgames.com/freesci/

MAINTAINER=		greid@ukug.uk.freebsd.org

LIB_DEPENDS=		ggi.2:${PORTSDIR}/graphics/libggi \
			png.4:${PORTSDIR}/graphics/png

HAS_CONFIGURE=		yes

CONFIGURE_ENV=		CFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

USE_GLIB=		yes

post-install:
	@${MKDIR} ${PREFIX}/share/freesci
	@${INSTALL_DATA} ${WRKSRC}/doc/sci.sgml ${PREFIX}/share/freesci

.include <bsd.port.mk>

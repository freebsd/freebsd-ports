# New ports collection makefile for:	Mike's Playlist Thingie
# Date created:				Sat Dec  8 22:27:55 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpt
PORTVERSION=	0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freetantrum

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Mike's Playlist Thingie is a fingerprinting based playlist generator

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		songprint.1:${PORTSDIR}/audio/songprint

USE_GNOME=	glib12
USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOC_FILES=	AUTHORS COPYING README config.txt

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/mpt ${PREFIX}/bin

.include <bsd.port.mk>

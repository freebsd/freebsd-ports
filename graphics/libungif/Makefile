# New ports collection makefile for:	libungif
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libungif
PORTVERSION=	4.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://prtr-13.ucsc.edu/pub/libungif/
MASTER_SITE_SUBDIR=	libs/graphics

PATCH_SITES=	http://www.arrakeen.demon.co.uk/giflib/
PATCHFILES=	libungif-4.1.0-19990224.patch.gz \
		libungif-4.1.0-19990305.patch.gz \
		libungif-4.1.0-19990322.patch.gz \
		libungif-4.1.0-19990523.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIBS=	yes

DOCDIR=		${PREFIX}/share/doc/libungif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UNCOMPRESSED_GIF ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	panorama
# Date created:				14 Sept 2000
# Whom:					Aaron VonderHaar <avh4@usa.net>
#
# $FreeBSD$
#

PORTNAME=	panorama
PORTVERSION=	0.13.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.debian.org/debian/pool/main/p/panorama/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig                        

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_${PORTVERSION}-2.1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		ungif:${PORTSDIR}/graphics/libungif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_FREETYPE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ENV=	NOPORTDOCS="${NOPORTDOCS}"
INSTALLS_SHLIB=	yes

CXX+=		${CPPFLAGS} ${LDFLAGS}

CPPFLAGS=	-I${LOCALBASE}/include/freetype1/freetype \
		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

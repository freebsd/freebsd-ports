# $FreeBSD$

PORTNAME=	libinstpatch
DISTVERSION=	1.0.0
DISTVERSIONSUFFIX=	+svn386
CATEGORIES=	audio
MASTER_SITES=	https://bigsearcher.com/mirrors/nongnu/gsequencer/1.4.x/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Instrument file software library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsndfile.so:audio/libsndfile

USES=		cmake gettext-runtime gnome localbase:ldflags pkgconfig tar:bz2
USE_GNOME=	glib20
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>

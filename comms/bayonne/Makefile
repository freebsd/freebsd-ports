# New ports collection makefile for:	bayonne
# Date created:				10 September 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	bayonne
PORTVERSION=	0.5.3
PORTREVISION=   1
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://www.voxilla.org/pub/bayonne/
MASTER_SITE_SUBDIR=	../old-gnu/bayonne

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-line general purpose voice telephony server

BROKEN=		"Port is outdated and there is no known working Hardware for FreeBSD > 4.4"

LIB_DEPENDS=	ccgnu2-1.0.0:${PORTSDIR}/devel/commoncpp \
		ccscript-1.4.0:${PORTSDIR}/lang/ccscript \
		ccaudio.0:${PORTSDIR}/audio/ccaudio

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
PLIST_SUB=	BAYONNE_VERSION=%{PORT_VERSION}

MAN8=		bayonne.8

post-extract:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|-release \$$\(LT_RELEASE\)||g'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

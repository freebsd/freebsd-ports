# ports collection makefile for:   lame
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	lame
PORTVERSION=	3.70
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.sunet.se/pub/multimedia/Berkeley/mpeg2/conformance-bitstreams/audio/mpeg2/software/technical_report/
DISTNAME=	dist10

PATCH_SITES=	http://www.sulaco.org/mp3/download/patches/
PATCHFILES=	lame${PORTVERSION}.patch.gz

MAINTAINER=	yoshiaki@kt.rim.or.jp

.if !defined(WITHOUT_X11)
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.endif

PATCH_DIST_STRIP = -p1

WRKSRC= 	${WRKDIR}/dist10/lsf/encoder/
USE_GMAKE=	YES
MAKE_ENV=	WITHOUT_X11=${WITHOUT_X11}
ALL_TARGET=	lame
RESTRICTED=	Condition is not clear

MAN1=		lame.1

do-install:
	@( cd ${WRKSRC}; ${INSTALL_PROGRAM} lame ${PREFIX}/bin )
	@( cd ${WRKSRC}; ${INSTALL_MAN} doc/man/lame.1 \
	 ${PREFIX}/man/man1 )

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/lame
	@${INSTALL_MAN} ${WRKSRC}/doc/html/*.html \
	 ${WRKSRC}/doc/html/*.css ${PREFIX}/share/doc/lame
.endif

.include <bsd.port.mk>

# New ports collection makefile for:   gogo no coder
# Version required:    2.26a
# Date created:        01 July 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

DISTNAME=	gogo226a
PKGNAME=	gogo-2.26a
CATEGORIES=	audio
MASTER_SITES=	http://homepage1.nifty.com/herumi/soft/gogo2/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	nakai@FreeBSD.org

# More than version 0.98
BUILD_DEPENDS=	nasm-0.98:${PORTSDIR}/devel/nasm
.if !defined(MINIMAL)
RUN_DEPENDS=	cdda2wav:${PORTSDIR}/sysutils/cdrecord \
		list_audio_tracks:${PORTSDIR}/sysutils/cdrecord
.endif

USE_GMAKE=	yes
ALL_TARGET=	gogo
.if(!defined(KANJI))
MAKE_ARGS+=	DONT_USE_KANJI=-DNO_KANJI
.else
MAKE_ARGS+=	DONT_USE_KANJI=
.endif
RESTRICTED=	Condition is not clear

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin
.if !defined(MINIMAL)
	${INSTALL_SCRIPT} ${WRKSRC}/sakai/cdda2mp3.bsd \
		${PREFIX}/bin/cdda2mp3.gogo
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gogo
	${INSTALL_DATA} ${WRKSRC}/sakai/cdda2mp3.txt \
		${PREFIX}/share/doc/gogo/cdda2mp3.gogo.jp
	${INSTALL_DATA} ${WRKSRC}/sakai/readme_e.txt \
		${PREFIX}/share/doc/gogo/cdda2mp3.gogo.en
.endif
.endif

.include <bsd.port.mk>

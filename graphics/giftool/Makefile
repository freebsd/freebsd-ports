# New ports collection makefile for:   giftool
# Date created:        14 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	giftool
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.sbs.de/pub/www/tools/giftool/

MAINTAINER=	nakai@FreeBSD.org

NO_CDROM=	"Shareware"

NO_WRKSUBDIR=	yes
ALL_TARGET=	giftool

.if defined(RETVALUE)
pre-patch::
	@${ECHO_MSG} "Return value patch enabled....."
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa
.endif
.if defined(MALLOCSIZE)
pre-patch::
	@${ECHO_MSG} "Malloc size improve parch enabled....."
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ab
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/giftool ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/giftool
.for file in COPYRIGHT README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/giftool
.endfor
	${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/share/doc/giftool

post-install:
.if !defined(BATCH)
	@ /usr/bin/more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>

# New ports collection makefile for:   giftool
# Version required:    1.0
# Date created:        14 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1997/06/04 07:34:49 asami Exp $
#

DISTNAME=	giftool-1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.sbs.de/pub/www/tools/giftool/

MAINTAINER=	nacai@iname.com

NO_CDROM=	"Shareware"

NO_WRKSUBDIR=	yes
ALL_TARGET=	giftool

pre-clean:
	@${RM} -f ${PATCHDIR}/patch-a[bc]

pre-patch:
.if defined(RETVALUE)
	@${ECHO_MSG} "Return value patch enabled....."
	@${CP} ${FILESDIR}/patch-aa ${PATCHDIR}
.endif
.if defined(MALLOCSIZE)
	@${ECHO_MSG} "Malloc size improve parch enabled....."
	@${CP} ${FILESDIR}/patch-ab ${PATCHDIR}
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

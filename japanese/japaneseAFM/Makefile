# New ports collection makefile for: japanese AFM files
# Version required:	1.0
# Date created:		11 September 1997
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.1.1.1 1997/10/14 08:22:02 max Exp $
#

DISTNAME=	japaneseAFM
PKGNAME=	ja-japaneseAFM-1.0
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

AFMDIR=		${PREFIX}/share/fonts/afm

do-install:
	@${MKDIR} ${AFMDIR}
	@${INSTALL_DATA} ${WRKSRC}/* ${AFMDIR}
	@rm -f ${AFMDIR}/PLIST.mktmp

.include <bsd.port.mk>

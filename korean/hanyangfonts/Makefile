# New ports collection makefile for:    hanyangfonts
# Version required:     ?
# Date created:         22 Mar 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.2 1997/07/13 18:49:20 max Exp $
#

DISTNAME=       hanyang-font-pcf
PKGNAME=        ko-hanyangfonts-1.0
CATEGORIES=     korean x11
MASTER_SITES=   ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
                ftp://sunsite.kren.nm.kr/pub/packages/hangul/fonts/

MAINTAINER=     junker@jazz.snu.ac.kr

USE_X11=        yes
NO_WRKSUBDIR=   yes

do-build:
	@cd ${WRKSRC}; \
	for fn in \
	  hgm10 hgm12 hgm14 hgm16 hgm18 hgm20  \
	  hmm10 hmm12 hmm14 hmm16 hmm18 hmm20; \
	do \
	  compress $$fn.pcf; \
	  echo $$fn "compressed"; \
	done; \
	mkfontdir .

do-install:
	@cd ${WRKSRC}; \
	${MKDIR} ${PREFIX}/lib/X11/fonts/korean/hanyang; \
	for fn in \
	  hgm10 hgm12 hgm14 hgm16 hgm18 hgm20  \
	  hmm10 hmm12 hmm14 hmm16 hmm18 hmm20; \
	do \
	  ${INSTALL_DATA} $$fn.pcf.Z ${PREFIX}/lib/X11/fonts/korean/hanyang; \
	done; \
	${INSTALL_DATA} fonts.dir ${PREFIX}/lib/X11/fonts/korean/hanyang

post-install:
	@${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL
	
.include <bsd.port.mk>

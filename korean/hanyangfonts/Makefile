# New ports collection makefile for:    hanyangfonts
# Version required:     ?
# Date created:         22 Mar 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.5 1998/08/05 09:31:21 asami Exp $
#

DISTNAME=       hanyang-font-pcf
PKGNAME=        ko-hanyangfonts-1.0
CATEGORIES=     korean x11-fonts
MASTER_SITES=   ftp://ftp.kaist.ac.kr/pub/hangul/fonts/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/fonts/

MAINTAINER=     junker@jazz.snu.ac.kr

USE_X_PREFIX=        yes
NO_WRKSUBDIR=   yes

FONTS=		hgm10 hgm12 hgm14 hgm16 hgm18 hgm20 \
		hmm10 hmm12 hmm14 hmm16 hmm18 hmm20

do-build:
	@cd ${WRKSRC}; \
	for fn in ${FONTS}; do \
		${GZIP_CMD} $$fn.pcf; \
		${ECHO} $$fn "compressed"; \
	done; \

do-install:
	@cd ${WRKSRC}; \
	for file in ${FONTS}; do \
		${INSTALL_DATA} "$$file".pcf.gz ${PREFIX}/lib/X11/fonts/misc; \
	done; \
	mkfontdir ${PREFIX}/lib/X11/fonts/misc

.include <bsd.port.mk>

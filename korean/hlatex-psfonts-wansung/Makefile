# New ports collection makefile for:	HLaTeX-0.95 PS fonts
# Version required:     0.95
# Date created:		2 Apr 1997
# Whom:			Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.1.1.1 1997/06/04 08:29:47 asami Exp $
#

DISTNAME=       PS-HLaTeX-pfb
PKGNAME=	ko-hlatexpsfonts-0.95
CATEGORIES=	korean
MASTER_SITES=	ftp://sunsite.kren.nm.kr/pub/packages/TeX/languages/korean/HLaTeX/fonts/ \
		ftp://ftp.kornet.nm.kr/pub/Tex/language/korean/HLaTeX/fonts/
MAINTAINER=	junker@jazz.snu.ac.kr

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	@cd ${WRKDIR}; \
	${MKDIR} ${PREFIX}/share/fonts/HLaTeX-0.95-pfb/; \
	for dir in phmj pkgs pkmg pkyt phgt pkgr pkgt pkmj; \
	do \
	  ${CP} -r $$dir ${PREFIX}/share/fonts/HLaTeX-0.95-pfb/; \
	done; \
	${INSTALL_DATA} Fontmap.local ${PREFIX}/share/fonts/HLaTeX-0.95-pfb/

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

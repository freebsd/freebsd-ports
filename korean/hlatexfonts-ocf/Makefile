# New ports collection makefile for:	HLaTeX OCF fonts collection
# Date created:		30 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	hlatexfonts-ocf
PORTVERSION=	1.0
CATEGORIES=	korean print
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/users/cjh/gs-ko/
DISTNAME=	${PORTNAME}
DISTFILES=	HLaTeX-Myoungjo-OCF-PS.tar.gz HLaTeX-Gothic-OCF-PS.tar.gz

MAINTAINER=	cjh@kr.freebsd.org
COMMENT=	HLaTeX(OCF format) fonts collection

BUILD_DEPENDS=	$(LOCALBASE)/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

NO_BUILD=	YES

do-configure:
.for FAMILY in Myoungjo Gothic
	${SED} -e 's@(@(HLaTeX-${FAMILY}\/@' \
		< ${WRKDIR}/HLaTeX-${FAMILY}/Fontmap.HLaTeX-${FAMILY} \
		> ${WRKDIR}/HLaTeX-${FAMILY}/Fontmap.${FAMILY}
	${RM} ${WRKDIR}/HLaTeX-${FAMILY}/Fontmap.HLaTeX-${FAMILY}
.endfor

do-install:
.for FAMILY in Myoungjo Gothic
	${MKDIR} ${PREFIX}/share/ghostscript/fonts/HLaTeX-${FAMILY}
.endfor
	${CP} ${PREFIX}/share/ghostscript/fonts/Fontmap \
	      ${PREFIX}/share/ghostscript/fonts/HLaTeX-Myoungjo/Fontmap.before
.for FAMILY in Myoungjo Gothic
	${INSTALL_DATA} ${WRKDIR}/HLaTeX-${FAMILY}/* \
			${PREFIX}/share/ghostscript/fonts/HLaTeX-${FAMILY}/
	${CAT} ${WRKDIR}/HLaTeX-${FAMILY}/Fontmap.${FAMILY} \
	    >> ${PREFIX}/share/ghostscript/fonts/Fontmap
.endfor

.include <bsd.port.mk>

# New ports collection makefile for:    mendexk-sjis
# Version required:     2.4b
# Date created:         1 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $Id$
#

DISTNAME=	mendexk2.4b
PKGNAME=	ja-mendexk-sjis-2.4b
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex215/ \
		ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/ptex215/web2c/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${KPATHSEA_PARENT}${EXTRACT_SUFX}

MAINTAINER=	watanabe@zlab.phys.nagoya-u.ac.jp

BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

USE_GMAKE=      yes

MANLANG=	ja
MAN1=		mendex.1

KPATHSEA_PARENT=	web2c-7.0

KANJI_FILES=	kana.h ktable.h

pre-configure:
	@(\
	  cd ${WRKDIR}/${KPATHSEA_PARENT}/kpathsea ; \
	  ./configure --prefix=${PREFIX} \
	)
	@(\
	  cd ${WRKSRC} ; \
	  for i in ${KANJI_FILES}; do \
	    ${MV} $$i $$i.orig ; \
	    nkf -s $$i.orig > $$i ; \
	  done \
	)

do-build:
	@( cd ${WRKDIR}/${KPATHSEA_PARENT}/kpathsea ; ${GMAKE} )
	@( cd ${WRKSRC} ; ${MAKE} kpathsea_parent=../${KPATHSEA_PARENT} )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mendex ${PREFIX}/bin
	@(\
	  if [ ! -d ${PREFIX}/man/${MANLANG}/man1 ] ; then \
	    ${MKDIR} ${PREFIX}/man/${MANLANG}/man1 ; fi \
	)
	@${INSTALL_MAN} ${WRKSRC}/mendex.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	@(\
	  if [ ! -d ${PREFIX}/share/doc/mendex ] ; then \
	    ${MKDIR} ${PREFIX}/share/doc/mendex ; fi \
	)
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mendex
.endif

.include <bsd.port.mk>

# New ports collection makefile for: jp-jlatex209
# Version required:	a1.7-n1.52
# Date created:		4 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id$
#

DISTNAME?=	jp-jlatex209-a17-n152
CATEGORIES=	japanese print
MASTER_SITES=	ftp://bash.cc.keio.ac.jp/pub/TeX/ASCII/ \
		ftp://ftp.iis.u-tokyo.ac.jp/TeX/NTT-JTeX/:old/ \
		ftp://ftp.iis.u-tokyo.ac.jp/TeX/fonts/pk/ \
		ftp://ftp.waseda.ac.jp/pub3/tex/ascii/
DISTFILES=	jtex-1.52.tar.gz tfm-files.tar.Z jtex1.7.tar.gz pTeX-JIS-patch

MAINTAINER=	mita@jp.FreeBSD.org

USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	jtex-1.52.tar.gz

# Which latex to be made at BATCH mode.  BOTH, ASCII, NTT are available.
BATCH_TEX?=	BOTH

post-extract:
	@(\
	  cd ${WRKSRC} ; \
	  if [ ! -d jtex1.7 ] ; then mkdir jtex1.7 ; fi ; \
	  cd jtex1.7 ; \
	  tar xzf ${DISTDIR}/jtex1.7.tar.gz ; \
	  cd ptex/ptex ; \
	  ${CP} -R ../../jtex/web2cdir . ; \
	  ${CP} -R ../../jtex/jtangle . \
	)

pre-build:
.if defined(BATCH)
	@(\
	  cd ${WRKSRC} ; \
	  /bin/sh ${FILESDIR}/select.sh ${FILESDIR} ${DISTDIR} ${PKGDIR} ${BATCH_TEX}; \
	)
.else
	@(\
	  cd ${WRKSRC} ; \
	  /bin/sh ${FILESDIR}/select.sh ${FILESDIR} ${DISTDIR} ${PKGDIR} SELECT ; \
	)
.endif

post-install:
.if !defined(BATCH)
	@(\
	  if [ -e /usr/local/share/tex/BOTH ] ;  \
	    then /bin/sh ${FILESDIR}/linkselect.sh ; \
	  fi \
	)
.endif

pre-reinstall:
	@${RM} -f ${INSTALL_COOKIE}
	@${RM} -f ${PACKAGE_COOKIE}
	@(\
	  cd ${WRKSRC} ; \
	  ${MAKE} reinstall DISTDIR=${DISTDIR} FILESDIR=${FILESDIR} \
	)

.include <bsd.port.mk>

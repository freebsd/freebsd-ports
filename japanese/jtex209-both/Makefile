# New ports collection makefile for: ja-jlatex209
# Date created:		4 Nov 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jlatex209
PORTVERSION=	${_PORTVERSION}
PKGNAMESUFFIX=	${_PKGNAMESUFFIX}
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.iis.u-tokyo.ac.jp/TeX/NTT-JTeX/:old/ \
		ftp://ftp.iis.u-tokyo.ac.jp/TeX/fonts/pk/ \
		ftp://ftp.waseda.ac.jp/pub/tex/ascii-OLD/
DISTFILES=	jtex-${NTT_VERSION}.tar.gz \
		tfm-files.tar.Z \
		jtex${ASCII_VERSION}.tar.gz \
		pTeX-JIS-patch

MAINTAINER=	mita@jp.FreeBSD.org

ASCII_VERSION=	1.7
NTT_VERSION=	1.52

#MANUAL_PACKAGE_BUILD=	incompatible with other versions of jtex-*
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=	jtex-${NTT_VERSION}.tar.gz
USE_BISON=	yes

# Which latex to be made at BATCH mode.  BOTH, ASCII, NTT are available.
BATCH_TEX?=	BOTH

.if ${BATCH_TEX} == BOTH
_PORTVERSION=	${ASCII_VERSION}+${NTT_VERSION}
_PKGNAMESUFFIX=	-ascii+ntt
.elif ${BATCH_TEX} == ASCII
_PORTVERSION=	${ASCII_VERSION}
_PKGNAMESUFFIX=	-ascii
.elif ${BATCH_TEX} == NTT
_PORTVERSION=	${NTT_VERSION}
_PKGNAMESUFFIX=	-ntt
.endif

post-extract:
	@(\
	  cd ${WRKSRC} ; \
	  ${MKDIR} jtex${ASCII_VERSION} ; \
	  cd jtex1.7 ; \
	  tar xzf ${DISTDIR}/jtex${ASCII_VERSION}.tar.gz ; \
	  cd ptex/ptex ; \
	  ${CP} -R ../../jtex/web2cdir . ; \
	  ${CP} -R ../../jtex/jtangle . \
	)

pre-build:
.if defined(BATCH)
	@(\
	  cd ${WRKSRC} ; \
	  ${SH} ${FILESDIR}/select.sh ${FILESDIR} ${DISTDIR} ${PKGDIR} ${BATCH_TEX}; \
	)
.else
	@(\
	  cd ${WRKSRC} ; \
	  ${SH} ${FILESDIR}/select.sh ${FILESDIR} ${DISTDIR} ${PKGDIR} SELECT ; \
	)
.endif

post-install:
.if !defined(BATCH)
	@(\
	  if [ -e ${PREFIX}/share/tex/BOTH ] ;  \
	    then ${SH} ${FILESDIR}/linkselect.sh ; \
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

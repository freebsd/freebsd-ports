# New ports collection makefile for:	Wnn for Japanese
# Date created:		20 July 1997
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Wnn
PORTVERSION=	4.2
CATEGORIES?=	japanese
MASTER_SITES=	ftp://ftp.u-tokyo.ac.jp/pub/Japanese/Wnn/ \
		ftp://ftp.wg.omron.co.jp/pub/Wnn/dic/pubdic+/ \
		http://www.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/Wnn/
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${WNN_EXTRA_PATCH}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	taoka@FreeBSD.org

USE_XLIB=	yes
INSTALLS_SHLIBS=	yes
PATCHDIR=	${.CURDIR}/../../japanese/Wnn/patches
FILESDIR=	${.CURDIR}/../../japanese/Wnn/files
PKGDIR=		${.CURDIR}/../../japanese/Wnn/pkg
WRKSRC=		${WRKDIR}/Xsi

WNN_EXTRA_PATCH= ${DISTNAME}.patch-981201.tar.gz
MAKE_ENV+=	 PATH=/usr/bin:$${PATH} PORT_IMAKE_DEFINES='${WNN_DEF}'

.if defined(BATCH)
BATCH=	yes	# make sure it's not empty
.endif

.include <bsd.port.pre.mk>

.if ${PKGNAMEPREFIX} == ja-
DISTFILES+=	pubdic+.tar.gz pubdic+-fix01.gz pubdic+.diff pubdic+.special.diff
PORT_DOCDIR=	${PREFIX}/share/doc/ja-Wnn
DOC_FROM=	${WRKSRC}/Wnn
BuildWnn=	YES
BuildJlibV3=	YES
LOCAL_MAN_LANG=	ja
SHARED_LIB=	libwnn4
.else
BuildWnn=	NO
.endif
.if ${PKGNAMEPREFIX} == zh-
PORT_DOCDIR=	${PREFIX}/share/doc/zh-Wnn
DOC_FROM=	${WRKSRC}/cWnn
BuildCWnn=	YES
SHARED_LIB=	libcwnn4
.else
BuildCWnn=	NO
.endif
.if ${PKGNAMEPREFIX} == ko-
# kWnn has no manual.
BuildKWnn=	YES
SHARED_LIB=	libkwnn4
.else
BuildKWnn=	NO
.endif
BuildXwnmo=	YES
# pubdic+
PUBDICPDIR=	${WRKSRC}/pubdic+
WDICS=	bio.u computer.u kihon.u setsuji.u tankan.u \
	chimei.u jinmei.u koyuu.u symbol.u special.u
ATOD=	${WRKSRC}/Wnn/jutil/atod -h ${WRKSRC}/Wnn/jd/hinsi.data
#WNN_DEF+=	-DBuildPubdic=NO
# TOPDIR should be a full path provided we build a shared library.
WNN_DEF+=	-DTOPDIR=${WRKSRC}

post-extract:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}${WNN_EXTRA_PATCH} ${EXTRACT_AFTER_ARGS} \
		-C ${WRKSRC}
	${LN} -sf Project.tmpl ${WRKSRC}/config/X11.tmpl
.if ${PKGNAMEPREFIX} == ja-
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}pubdic+.tar.gz ${EXTRACT_AFTER_ARGS} -C ${WRKSRC}
.endif

pre-patch:
	cd ${WRKSRC}; ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/Wnn-patch-01Dec98

#### pubdic+
.if ${PKGNAMEPREFIX} == ja-
post-patch:
	cd ${PUBDICPDIR}; \
	${GZCAT} ${_DISTDIR}pubdic+-fix01.gz | ${PATCH} --quiet; \
	${PATCH} --quiet < ${_DISTDIR}pubdic+.diff; \
	${PATCH} --quiet < ${_DISTDIR}pubdic+.special.diff
.endif

pre-configure:
	for file in ${WRKSRC}/config/Project.tmpl \
		${WRKSRC}/Contrib/dic/gerodic/Makefile; do \
	  ${MV} $$file $$file.orig2; \
	  ${SED} -e 's!^\([ ]*PREFIX = \).*$$!\1${PREFIX}!' \
		-e 's!%%LOCAL_MAN_LANG%%!${LOCAL_MAN_LANG}!' \
		-e 's!%%BuildWnn%%!${BuildWnn}!' \
		-e 's!%%BuildCWnn%%!${BuildCWnn}!' \
		-e 's!%%BuildKWnn%%!${BuildKWnn}!' \
		-e 's!%%BuildXwnmo%%!${BuildXwnmo}!' \
		-e 's!%%BuildJlibV3%%!${BuildJlibV3}!' \
		$$file.orig2 > $$file; \
	done

do-configure:
	 (cd ${WRKSRC}; \
	 imake -DUseInstalled -I${WRKSRC}/config \
		 -I${X11BASE}/lib/X11/config -DTOPDIR=${WRKSRC}; \
	 ${MAKE} Makefiles; \
	 ${MAKE} clean; \
	 ${MAKE} includes; \
	 ${MAKE} depend )

pre-build:
#### pubdic+
.if ${PKGNAMEPREFIX} == ja-
	cd ${PUBDICPDIR}; ${XMKMF}; ${MAKE} wnn; \
	cd ${WRKSRC}/Pubdic; \
	for file in ${WDICS}; do \
		${MV} -f $$file $$file.org; \
		${MV} ../pubdic+/$$file . ; \
		hdfile=`echo $$file | ${SED} 's/\\.u/.hd/'`; \
		${MV} -f $$hdfile $$hdfile.org; \
		${SED} 's,(pubdic),(pubdic+),' $$hdfile.org > $$hdfile; \
	done
.endif

# These are necesary because this package uses a different Makefile for
#  building and installing etc.
#do-build:
#	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} Makefile.inst World)

#### gerodic
.if ${PKGNAMEPREFIX} == ja-
post-build:
	cd ${WRKSRC}/Contrib/dic/gerodic; \
	${ATOD} -h ${WRKSRC}/Pubdic/hinsi.data g-jinmei.dic < g-jinmei.u
.endif

pre-install:
	@${SETENV} BATCH=${BATCH} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
#### gerodic
.if ${PKGNAMEPREFIX} == ja-
	cd ${WRKSRC}/Contrib/dic/gerodic; \
	make all install
.endif
####
# This package uses imake's "install.man" target to install man pages but
#  I can't define USE_IMAKE because it doesn't involve xmkmf
	@cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
.if !defined(NOPORTDOCS)
.if defined(PORT_DOCDIR)
	${MKDIR} ${PORT_DOCDIR}
	@(cd ${DOC_FROM}; tar cvf - manual manual.en | \
		(cd ${PORT_DOCDIR}; tar xf -))
	@${CHOWN} -R bin.bin ${PORT_DOCDIR}
.endif
.endif
### for the shared libray
	if [ X"${PORTOBJFORMAT}" != Xelf ]; then \
		${LN} -sf ${SHARED_LIB}.so.1.0 \
			${X11BASE}/lib/${SHARED_LIB}.so; \
	fi

.include <bsd.port.post.mk>

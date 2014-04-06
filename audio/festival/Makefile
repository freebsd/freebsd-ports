# Created by: trevor
# $FreeBSD$

PORTNAME=	festival
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	${DISTNAME}-release.tar.gz 	\
		speech_tools-${PORTVERSION}-release.tar.gz

PATCHFILES=	src_modules_diphone_diphone.h.diff:debian	\
		src_modules_diphone_di_io.cc.diff:debian	\
		src_modules_diphone_diphone.cc.diff:debian	\
		src_modules_donovan_t2s.h.diff:debian		\
		src_modules_UniSyn_diphone_UniSyn_diphone.cc.diff:debian \
		festival_el_utf8.diff:debian	\
		lintianspellpatch.diff:debian	\
		hts21compat.diff:debian	\
		languagespatch.diff:debian \
		${SPT_PATCHES:C/.*/patch-speech__tools_\0:netbsd/}
PATCH_SITES=	ftp://ftp.netbsd.org/pub/pkgsrc/current/pkgsrc/audio/festival/patches/:netbsd	\
		http://patch-tracker.debian.org/patch/series/dl/festival/1:2.1~release-5.1/:debian

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multi-lingual speech synthesis system

OPTIONS_DEFINE=	NAS ESD
OPTIONS_DEFAULT=NAS ESD
ESD_DESC=	${ESOUND_DESC}

DIST_SUBDIR=	festival
 
CXXFLAGS+=	-DFTLIBDIR=${LOCALBASE}/share/festival/lib
CONFIGURE_WRKSRC=	${WRKDIR}/festival
USES=		gmake
SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival
MAKE_ENV+=	GCC="${CC}" \
		GXX="${CXX}" \
		EST_HOME=${SPEECHTOOLS} \
		EGCS_CC="${CC}" \
		EGCS_CXX="${CXX}"
WRKSRC=		${WRKDIR}

SPT_PATCHES=	base__class_EST__TVector.cc	\
		base__class_inst__tmpl_vector__dmatrix__t.cc	\
		base__class_inst__tmpl_vector__dvector__t.cc	\
		base__class_inst__tmpl_vector__fmatrix__t.cc	\
		config_compilers_gcc__defaults.mak	\
		include_EST__Ngrammar.h	\
		include_EST__SCFG.h	\
		include_EST__String.h	\
		include_EST__error.h	\
		include_ling__class_EST__FeatureFunctionPackage.h	\
		include_unix_EST__socket__unix.h	\
		stats_dynamic__program.cc	\
		utils_EST__ServiceTable.cc

do-build:
.for d in speech_tools festival
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKDIR}/$d ${MAKE_FLAGS} Makefile \
		${MAKE_ARGS}
.endfor

# Can not make test in `festival', because the voices may not be installed
# XXX: this should fail, if the verdict is not "CORRECT"...
post-build test:
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKDIR}/speech_tools test

# The below is needed, because Debian's patches expect a different
# directory-name
pre-patch:
	${LN} -s festival ${WRKSRC}/festival-2.1~release
	${LN} -s festival ${WRKSRC}/b

post-patch::
	${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g'	\
		${WRKSRC}/*/config/systems/default.mak

.include <bsd.port.options.mk>

.for m in nas esd
.	if ${PORT_OPTIONS:M${m:U}}
LIB_DEPENDS+=	lib${m:nas=audio}.so:${PORTSDIR}/audio/${m:esd=esound}
post-patch::
	${REINPLACE_CMD} -e 's,# INCLUDE_MODULES += ${m:U}_AUDIO,INCLUDE_MODULES += ${m:U}_AUDIO,' \
		${WRKDIR}/*/config/config.in
CONFIGURE_ARGS+=--enable-$m
.	else
CONFIGURE_ARGS+=--disable-$m
.	endif
.endfor

do-configure:
.for d in speech_tools festival
	@cd ${WRKDIR}/$d && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}; then \
		${ECHO_CMD} "===>  configuration script for $d failed."; \
		${FALSE}; \
	fi
	# This step helps non-i386 systems and is harmless on i386
	-${LN} -s ix86_FreeBSD.mak ${WRKDIR}/$d/config/systems/${ARCH}_unknown.mak
.endfor
	${REINPLACE_CMD} -E -e 's,^(CC|CXX) *=,\1 ?=,' \
	    -e 's,^(CFLAGS|CXXFLAGS) *=,\1 +=,' \
	    -e 's,^OPTIMI,#OPTIMI,' \
	    ${WRKSRC}/speech_tools/config/compilers/gcc*.mak
	# This step helps to use a compiler, the vendor has not seen before:
	${TEST} -e ${WRKDIR}/speech_tools/config/compilers/${CC}.mak ||	\
		${LN} -s gcc_defaults.mak ${WRKDIR}/speech_tools/config/compilers/${CC}.mak

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib/voices/english/
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib/voices/spanish/
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib/dicts
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${FIND} ${FESTIVAL} -type f -name *.orig -delete
	cd ${FESTIVAL} && ${CP} -pPR lib examples ${STAGEDIR}${DATADIR}
	${RM} -rf ${STAGEDIR}${DATADIR}/lib/etc/Makefile ${STAGEDIR}${DATADIR}/lib/etc/*FreeBSD* \
	    ${STAGEDIR}${DATADIR}/lib/etc/*unknown
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/*/audsp ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival ${STAGEDIR}${PREFIX}/libexec/festival.naked
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival_client ${STAGEDIR}${PREFIX}/libexec/festival_client.naked
	for n in festival.sh festival_client.sh sitevars.scm; \
	do {\
	  ${SED} "s%@PKG_FESTIVAL_LOCATION@%${DATADIR}%; \
	       s%@PKG_PREFIX@%${PREFIX}%" <${FILESDIR}/$$n > ${WRKDIR}/$$n ;} \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh ${STAGEDIR}${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh ${STAGEDIR}${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm ${STAGEDIR}${DATADIR}/lib/sitevars.scm
	${INSTALL_MAN} ${FESTIVAL}/doc/festival.1 ${STAGEDIR}${PREFIX}/man/man1/festival.1
	${INSTALL_MAN} ${FESTIVAL}/doc/festival_client.1 ${STAGEDIR}${PREFIX}/man/man1/festival_client.1

.include <bsd.port.mk>

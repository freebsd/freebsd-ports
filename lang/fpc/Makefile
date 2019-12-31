# Created by: John Merryweather Cooper et al
# $FreeBSD$

PORTNAME=	fpc
PORTVERSION=	3.0.4
PORTREVISION?=	3
CATEGORIES?=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://planetmirror.com/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/${PORTVERSION}/source/:source \
		ftp://freepascal.stack.nl/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		SF/freepascal/Source/${PORTVERSION}:source \
		http://leaf.dragonflybsd.org/~marino/dports-src/:DragonFlybootstrap \
		LOCAL/acm/freepascal/:bootstrap \
		LOCAL/acm/freepascal/:man
DISTFILES=	${DISTNAME:S/$/.source/}${EXTRACT_SUFX}:source
DIST_SUBDIR=	freepascal

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	Free Pascal compiler with Turbo and Delphi

ONLY_FOR_ARCHS=	amd64 i386

USES+=		gmake iconv
USE_BINUTILS=	yes
BOOTVER=	3.0.4
MANVER=		3.0.4

FPC_LDPATH?=	"${LOCALBASE}/bin/ld.bfd"

#USE_GITHUB=	yes
#GH_ACCOUNT=	fpc-svn
#GH_PROJECT=	fpc
FPCSRCDIR=	${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PPNAME=		ppc386
FPC_ARCH=	i386
PLIST_SUB+=	FPC_I386="" \
		FPC_AMD64="@comment "
.elif ${ARCH} == "amd64"
PPNAME=		ppcx64
FPC_ARCH=	x86_64
PLIST_SUB+=	FPC_I386="@comment " \
		FPC_AMD64=""
.endif

.if ${OPSYS} == FreeBSD
PLIST_SUB+=	FREEBSD=""
.else
PLIST_SUB+=	FREEBSD="@comment "
.endif

.if !defined(PKGNAMESUFFIX)
SUB_FILES=	pkg-message

BUILDNAME=	${FPC_ARCH}-${OPSYS:tl}
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		BUILDNAME=${BUILDNAME}
DISTFILES+=	${BOOTDIR}.tar.gz:${OPSYS:MDragonFly}bootstrap \
		fpc-${MANVER}.man.tar.gz:man
NEWFPCMAKE=	${WRKDIR}/${FPCSRCDIR}/utils/fpcm/bin/${BUILDNAME}/fpcmake
MAKE_ARGS+=	FPCMAKE=${NEWFPCMAKE} \
		FPCTARGET=${BUILDNAME} \
		ARCH=${FPC_ARCH} \
		OPT="${OPT}" \
		BSDHIER=1 \
		INSTALL="${INSTALL_DATA}" \
		INSTALLEXE="${INSTALL_PROGRAM}" \
		INSTALLSCR="${INSTALL_SCRIPT}" \
		INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		FPC_LDPATH=${FPC_LDPATH}
NEWPPC=		PP=${WRKSRC}/compiler/${PPNAME}
NEWFPC=		FPC=${WRKSRC}/compiler/${PPNAME}
BOOTDIR=	${PPNAME}-${BOOTVER}-${OPSYS:tl}
BOOTPPC=	PP=${WRKDIR}/${BOOTDIR}

do-extract:
# unpack binary distribution
	@${MKDIR} ${WRKDIR}
	@${TAR} -xzf ${_DISTDIR}/${BOOTDIR}.tar.gz \
		--directory ${WRKDIR} && ${CHMOD} +x ${WRKDIR}/${BOOTDIR}
# unpack man files
	@${TAR} -xzf ${_DISTDIR}/fpc-${MANVER}.man.tar.gz --directory ${WRKDIR}
# unpack source distribution
	@(cd ${WRKDIR} && ${GZIP_CMD} -dc \
		${_DISTDIR}/${DISTNAME:S/$/.source/}${EXTRACT_SUFX} | \
		${TAR} -xf - \
		${FPCSRCDIR}/compiler \
		${FPCSRCDIR}/rtl \
		${FPCSRCDIR}/utils/fpcmkcfg \
		${FPCSRCDIR}/packages/fcl-base \
		${FPCSRCDIR}/packages/fcl-process \
		${FPCSRCDIR}/packages/fcl-res \
		${FPCSRCDIR}/packages/fpmkunit \
		${FPCSRCDIR}/packages/hash \
		${FPCSRCDIR}/packages/libtar \
		${FPCSRCDIR}/packages/paszlib \
		${FPCSRCDIR}/packages/rtl-objpas \
		${FPCSRCDIR}/utils/fpcm)

post-patch:
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -i "" -e 's|900044|${OSVERSION}|g' \
		${WRKSRC}/rtl/freebsd/${FPC_ARCH}/*.as
	@${REINPLACE_CMD} -i "" -e 's|197|477|g' \
		${WRKSRC}/rtl/freebsd/sysnr.inc
.else
	@${REINPLACE_CMD} -i "" -e 's|400000|${DFLYVERSION}|g' \
		${WRKSRC}/rtl/dragonfly/${FPC_ARCH}/*.as
.endif
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e "s|s<>'c'|(s<>'c') and (s<>'iconv')|" \
			-e "s|%%FPC_LDPATH%%|${FPC_LDPATH}|g" \
				${WRKDIR}/${FPCSRCDIR}/compiler/systems/t_bsd.pas
	@${REINPLACE_CMD} -e 's|defined(bsd) and not ||' \
		${WRKDIR}/${FPCSRCDIR}/rtl/unix/cwstring.pp
.endif
	@${REINPLACE_CMD} -e '/samplecfg/ {s/INSTALLEXE/INSTALLSCR/;}' \
		${WRKDIR}/${FPCSRCDIR}/compiler/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKDIR}/${FPCSRCDIR}/packages/fpmkunit/src/fpmkunit.pp

do-build:
# build fpc compiler
	@${ECHO_MSG} "##### STARTING COMPILER #####"
	(cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} cycle ${MAKE_ARGS} ${BOOTPPC})
	@${ECHO_MSG} "##### COMPLETE COMPILER #####"

# build fpcmkcfg
	@${ECHO_MSG} "##### STARTING BOOTSTRAP FPMKUNIT #####"
	(cd ${WRKDIR}/${FPCSRCDIR}/packages/fpmkunit && ${SETENV} \
		${MAKE_ENV} ${MAKE_CMD} bootstrap ${MAKE_ARGS} ${NEWPPC})
	@${ECHO_MSG} "##### COMPLETE BOOTSTRAP FPMKUNIT #####"
.for component in fcl-res rtl-objpas fcl-base
	@${ECHO_MSG} "##### STARTING ${component:tu} #####"
	(cd ${WRKDIR}/${FPCSRCDIR}/packages/${component} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${NEWPPC})
	@${ECHO_MSG} "##### COMPLETE ${component:tu} #####"
.endfor
	@${ECHO_MSG} "##### STARTING FPMAKE #####"
	(cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcm && ${SETENV} \
		${MAKE_ENV} ${MAKE_CMD} release ${MAKE_ARGS} ${NEWPPC})
	@${ECHO_MSG} "##### COMPLETE FPMAKE #####"
.for component in hash paszlib libtar fcl-process fpmkunit
	@${ECHO_MSG} "##### STARTING ${component:tu} #####"
	(cd ${WRKDIR}/${FPCSRCDIR}/packages/${component} && ${SETENV} \
		${MAKE_ENV} ${MAKE_CMD} release ${MAKE_ARGS} ${NEWPPC})
	@${ECHO_MSG} "##### COMPLETE ${component:tu} #####"
.endfor
	@${ECHO_MSG} "##### STARTING FPCMKCFG #####"
	(cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcmkcfg && ${SETENV} \
		${MAKE_ENV} ${MAKE_CMD} release ${MAKE_ARGS} ${NEWPPC})
	@${ECHO_MSG} "##### COMPLETE FPCMKCFG #####"

do-install:
	# Installing fpc compiler
	(cd ${WRKDIR}/${FPCSRCDIR}/rtl && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} install ${MAKE_ARGS} ${NEWFPC})
	# Installing fpc runtime
	(cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} install ${MAKE_ARGS} ${NEWFPC})
	# Installing fpmkunit and its dependencies
.for component in hash paszlib libtar fcl-process fpmkunit
	(cd ${WRKDIR}/${FPCSRCDIR}/packages/${component} && ${SETENV} \
		${MAKE_ENV} ${MAKE_CMD} install ${MAKE_ARGS} ${NEWPPC})
.endfor
	# Installing fpcmkcfg
	${INSTALL_PROGRAM} ${WRKDIR}/${FPCSRCDIR}/utils/fpcmkcfg/bin/${BUILDNAME}/fpcmkcfg \
		${STAGEDIR}${PREFIX}/bin
	# Installing fpcmake
	${INSTALL_PROGRAM} ${NEWFPCMAKE} ${STAGEDIR}${PREFIX}/bin
	# Installing manpages
	${INSTALL_MAN} ${WRKDIR}/man/man1/* ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man/man5/* ${STAGEDIR}${MAN1PREFIX}/man/man5
	# symlinking compiler
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ../lib/fpc/${PORTVERSION}/${PPNAME})
	# creating sample configuration file
	${SH} "${STAGEDIR}${PREFIX}/lib/fpc/${PORTVERSION}/samplecfg" \
		"${STAGEDIR}${PREFIX}/lib/fpc/${PORTVERSION}" \
		"${STAGEDIR}${PREFIX}/etc"
	@${REINPLACE_CMD} -i "" -e 's|${STAGEDIR}||' \
		-e 's|^-Fl/usr/local/lib|-Fl${LOCALBASE}/lib;${LOCALBASE}/lib/qt4;${LOCALBASE}/lib/qt5|g' \
		${STAGEDIR}${PREFIX}/etc/fpc.cfg.sample

.else
.include "${MASTERDIR}/Makefile.units"
.endif
.include <bsd.port.post.mk>

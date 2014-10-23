# Created by: John Merryweather Cooper et al
# $FreeBSD$

PORTNAME=	fpc
PORTVERSION=	2.6.4
PORTREVISION?=	0
CATEGORIES?=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://planetmirror.com/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/${PORTVERSION}/source/:source \
		ftp://freepascal.stack.nl/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		SF/freepascal/Source/${PORTVERSION}:source \
		${MASTER_SITE_GOOGLE_CODE}:bootstrap \
		${MASTER_SITE_LOCAL:S|$|acm/freepascal/:bootstrap|} \
		${MASTER_SITE_GOOGLE_CODE}:man \
		${MASTER_SITE_LOCAL:S|$|acm/freepascal/:man|}
DISTFILES=	${DISTNAME:S/$/.source/}${EXTRACT_SUFX}:source
DIST_SUBDIR=	freepascal

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	Free Pascal compiler with Turbo and Delphi

PROJECTHOST=	bsdistfiles
USES=		gmake iconv
ONLY_FOR_ARCHS=	i386 amd64

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options

#OPT?=-Ur -CX
OPT?=-CX
FPCSRCDIR=	${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OPSYS} == DragonFly
IGNORE=		not supported on DragonFly yet
.endif

.if ${ARCH} == "i386"
PPNAME=		ppc386
FPC_ARCH=	i386
PLIST_SUB=	FPC_I386="" \
		FPC_AMD64="@comment "
.elif ${ARCH} == "amd64"
PPNAME=		ppcx64
FPC_ARCH=	x86_64
PLIST_SUB=	FPC_I386="@comment " \
		FPC_AMD64=""
.endif

.if !defined(PKGNAMESUFFIX)
SUB_FILES=	pkg-message

BUILDNAME=	${FPC_ARCH}-freebsd
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		BUILDNAME=${BUILDNAME}
DISTFILES+=	${PPNAME}-${PORTVERSION}-${OPSYS:tl}${EXTRACT_SUFX}:bootstrap \
		${DISTNAME:S/$/.man/}${EXTRACT_SUFX}:man
MAKE_ARGS+=	PP=${WRKDIR}/${PPNAME}-${PORTVERSION}-${OPSYS:tl} \
		FPCMAKE=${WRKDIR}/${FPCSRCDIR}/utils/fpcm/fpcmake \
		FPCTARGET=${BUILDNAME} \
		ARCH=${FPC_ARCH} \
		OPT="${OPT}" \
		BSDHIER=1 \
		INSTALL_PREFIX=${STAGEDIR}${PREFIX}

do-extract:
# unpack binary distribution
	@${MKDIR} ${WRKDIR}
	@${TAR} xfz ${_DISTDIR}/${PPNAME}-${PORTVERSION}-${OPSYS:tl}${EXTRACT_SUFX} --directory \
		${WRKDIR} && ${CHMOD} +x ${WRKDIR}/${PPNAME}-${PORTVERSION}-${OPSYS:tl}
# unpack man files
	@${TAR} xfz ${_DISTDIR}/${DISTNAME:S/$/.man/}${EXTRACT_SUFX} --directory \
		${WRKDIR}
# unpack source distribution
	@cd ${WRKDIR} && \
		${GZIP_CMD} -dc ${_DISTDIR}/${DISTNAME:S/$/.source/}${EXTRACT_SUFX} \
			| ${TAR} xf - ${FPCSRCDIR}/compiler ${FPCSRCDIR}/rtl \
				${FPCSRCDIR}/utils/fpcmkcfg ${FPCSRCDIR}/packages/fcl-base \
					${FPCSRCDIR}/packages/fcl-process ${FPCSRCDIR}/utils/fpcm

post-patch:
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -i "" -e 's|504000|${OSVERSION}|g' ${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${FPC_ARCH}/cprt0.as
.elif ${ARCH} == "amd64"
	@${REINPLACE_CMD} -i "" -e 's|700055|${OSVERSION}|g' ${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${FPC_ARCH}/cprt0.as
	@${REINPLACE_CMD} -i "" -e 's|502110|${OSVERSION}|g' ${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${FPC_ARCH}/gprt0.as
	@${REINPLACE_CMD} -i "" -e 's|700055|${OSVERSION}|g' ${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${FPC_ARCH}/prt0.as
.endif
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e "s|if (s<>'c') or reorder then|if ((s<>'c') and (s<>'iconv')) or reorder then|" \
		${WRKDIR}/${FPCSRCDIR}/compiler/systems/t_bsd.pas
	@${REINPLACE_CMD} -e 's|defined(bsd) and not ||' \
		${WRKDIR}/${FPCSRCDIR}/rtl/unix/cwstring.pp
.endif

do-build:
# build fpc compiler
	@cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} cycle ${MAKE_ARGS}
# build fpcmkcfg
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcm && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}
	@cd ${WRKDIR}/${FPCSRCDIR}/packages/fcl-base && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}
	@cd ${WRKDIR}/${FPCSRCDIR}/packages/fcl-process && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcmkcfg && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

do-install:
# 	Installing fpc compiler
	@cd ${WRKDIR}/${FPCSRCDIR}/rtl && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} install ${MAKE_ARGS}
# 	Installing fpc runtime
	@cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} install ${MAKE_ARGS}
# 	Installng fpcmkcfg
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcmkcfg && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} install ${MAKE_ARGS}
# 	Installng fpcmake
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcm && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} install ${MAKE_ARGS}
# 	Installing manpages
	${INSTALL_DATA} ${WRKDIR}/man/man1/* ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/man/man5/* ${STAGEDIR}${MAN1PREFIX}/man/man5

post-install:
	if [ -e "${STAGEDIR}${PREFIX}/bin/${PPNAME}" ]; then ${RM} -f "${STAGEDIR}${PREFIX}/bin/${PPNAME}"; fi
	${LN} -sf "${PREFIX}/lib/fpc/${PORTVERSION}/${PPNAME}" "${STAGEDIR}${PREFIX}/bin"
	${SH} "${STAGEDIR}${PREFIX}/lib/fpc/${PORTVERSION}/samplecfg" "${STAGEDIR}${PREFIX}/lib/fpc/${PORTVERSION}" "${STAGEDIR}${PREFIX}/etc"
	@${REINPLACE_CMD} -i "" -e 's|${STAGEDIR}||' \
		-e 's|^-Fl/usr/local/lib|-Fl${LOCALBASE}/lib;${LOCALBASE}/lib/qt4|g' ${STAGEDIR}${PREFIX}/etc/fpc.cfg.sample

.else
.include "${MASTERDIR}/Makefile.units"
.endif
.include <bsd.port.post.mk>

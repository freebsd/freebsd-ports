# Created by:	John Merryweather Cooper et al
# $FreeBSD$

PORTNAME=	fpc
PORTVERSION=	2.6.2
PORTREVISION?=	1
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
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386 amd64

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options

#OPT?=-Ur -CX
OPT?=-CX
FPCSRCDIR=	${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

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
DISTFILES+=	${PPNAME}-${PORTVERSION}-${OPSYS:L}${EXTRACT_SUFX}:bootstrap \
		${DISTNAME:S/$/.man/}${EXTRACT_SUFX}:man
MAKE_ENV+=	PP=${WRKDIR}/${PPNAME}-${PORTVERSION}-${OPSYS:L} \
		FPCMAKE=${WRKDIR}/${FPCSRCDIR}/utils/fpcm/fpcmake \
		FPCTARGET=${BUILDNAME} \
		ARCH=${FPC_ARCH} \
		OPT="${OPT}" \
		BSDHIER=1

MAN1=	bin2obj.1 \
	chmcmd.1 \
	chmls.1 \
	data2inc.1 \
	delp.1 \
	fd2pascal.1 \
	fp.1 \
	fpc.1 \
	fpclasschart.1 \
	fpcmake.1 \
	fpcmkcfg.1 \
	fpdoc.1 \
	fprcp.1 \
	fpcres.1 \
	fpcsubst.1 \
	fppkg.1 \
	grab_vcsa.1 \
	h2pas.1 \
	h2paspp.1 \
	makeskel.1 \
	plex.1 \
	postw32.1 \
	ppc386.1 \
	ppcarm.1 \
	ppcppc.1 \
	ppcsparc.1 \
	ppcx64.1 \
	ppdep.1 \
	ppudump.1 \
	ppufiles.1 \
	ppumove.1 \
	ptop.1 \
	pyacc.1 \
	rmcvsdir.1 \
	rstconv.1 \
	unitdiff.1
MAN5=	fpc.cfg.5 fpcmake.5 ptop.cfg.5

do-extract:
# unpack binary distribution
	@${MKDIR} ${WRKDIR}
	@${TAR} xfz ${_DISTDIR}/${PPNAME}-${PORTVERSION}-${OPSYS:L}${EXTRACT_SUFX} --directory \
		${WRKDIR} && ${CHMOD} +x ${WRKDIR}/${PPNAME}-${PORTVERSION}-${OPSYS:L}
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

do-build:
# build fpc compiler
	@cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${GMAKE} cycle ${MAKE_ENV}
# build fpcmkcfg
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcm && ${GMAKE} ${MAKE_ENV}
	@cd ${WRKDIR}/${FPCSRCDIR}/packages/fcl-base && ${GMAKE} ${MAKE_ENV}
	@cd ${WRKDIR}/${FPCSRCDIR}/packages/fcl-process && ${GMAKE} ${MAKE_ENV}
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcmkcfg && ${GMAKE} ${MAKE_ENV}

do-install:
# 	Installing fpc compiler
	@cd ${WRKDIR}/${FPCSRCDIR}/rtl && ${GMAKE} install ${MAKE_ENV}
# 	Installing fpc runtime
	@cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${GMAKE} install ${MAKE_ENV}
# 	Installng fpcmkcfg
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcmkcfg && ${GMAKE} install ${MAKE_ENV}
# 	Installng fpcmake
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcm && ${GMAKE} install ${MAKE_ENV}
# 	Installing manpages
	${INSTALL_DATA} ${WRKDIR}/man/man1/* ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/man/man5/* ${MAN1PREFIX}/man/man5

post-install:
	if [ -e "${PREFIX}/bin/${PPNAME}" ]; then ${RM} -f "${PREFIX}/bin/${PPNAME}"; fi
	${LN} -s "${PREFIX}/lib/fpc/${PORTVERSION}/${PPNAME}" "${PREFIX}/bin"
	${SH} "${PREFIX}/lib/fpc/${PORTVERSION}/samplecfg" "${PREFIX}/lib/fpc/${PORTVERSION}" "${PREFIX}/etc"
	@${REINPLACE_CMD} -i "" -e 's|^-Fl/usr/local/lib|-Fl${LOCALBASE}/lib;${LOCALBASE}/lib/qt4|g' ${PREFIX}/etc/fpc.cfg.sample
	@if [ ! -f ${PREFIX}/etc/fpc.cfg ]; then \
		${CP} ${PREFIX}/etc/fpc.cfg.sample ${PREFIX}/etc/fpc.cfg; \
	fi
	@${CAT} ${PKGMESSAGE}

.else
.include "${MASTERDIR}/Makefile.units"
.endif
.include <bsd.port.post.mk>

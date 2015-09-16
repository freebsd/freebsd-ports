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
		http://leaf.dragonflybsd.org/~marino/dports-src/:DragonFlybootstrap \
		SF/freepascal/Source/${PORTVERSION}:source \
		LOCAL/acm/freepascal/:bootstrap \
		LOCAL/acm/freepascal/:man
DISTFILES=	${DISTNAME}.source.tar.gz:source
DIST_SUBDIR=	freepascal

MAINTAINER?=	freebsd-fpc@FreeBSD.org
COMMENT?=	Free Pascal compiler with Turbo and Delphi

PROJECTHOST=	bsdistfiles
USES=		gmake iconv
ONLY_FOR_ARCHS=	i386 amd64
BOOTVER=	2.6.4

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
		${DISTNAME}.man.tar.gz:man
MAKE_ARGS+=	FPCMAKE=${WRKDIR}/${FPCSRCDIR}/utils/fpcm/fpcmake \
		FPCTARGET=${BUILDNAME} \
		ARCH=${FPC_ARCH} \
		OPT="${OPT}" \
		BSDHIER=1 \
		INSTALL_PREFIX=${STAGEDIR}${PREFIX}
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
	@${TAR} -xzf ${_DISTDIR}/${DISTNAME}.man.tar.gz --directory ${WRKDIR}
# unpack source distribution
	@(cd ${WRKDIR} && \
		${GZIP_CMD} -dc ${_DISTDIR}/${DISTNAME}.source.tar.gz | \
		${TAR} -xf - \
		${FPCSRCDIR}/compiler \
		${FPCSRCDIR}/rtl \
		${FPCSRCDIR}/utils/fpcmkcfg \
		${FPCSRCDIR}/packages/fcl-base \
		${FPCSRCDIR}/packages/fcl-process \
		${FPCSRCDIR}/utils/fpcm)

post-patch:
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -i "" -e 's|504000|${OSVERSION}|g' \
		${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${FPC_ARCH}/cprt0.as
.elif ${ARCH} == "amd64"
.  if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -i "" -e 's|700055|${OSVERSION}|g' \
		${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${FPC_ARCH}/cprt0.as
	@${REINPLACE_CMD} -i "" -e 's|502110|${OSVERSION}|g' \
		${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${FPC_ARCH}/gprt0.as
	@${REINPLACE_CMD} -i "" -e 's|700055|${OSVERSION}|g' \
		${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${FPC_ARCH}/prt0.as
.  else
	@${REINPLACE_CMD} -i "" -e 's|400000|${DFLYVERSION}|g' \
		${WRKSRC}/${FPCSRCDIR}/rtl/dragonfly/${FPC_ARCH}/*.as
.  endif
.endif
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} -e "s|if (s<>'c') or reorder then|if ((s<>'c') and (s<>'iconv')) or reorder then|" \
		${WRKDIR}/${FPCSRCDIR}/compiler/systems/t_bsd.pas
	@${REINPLACE_CMD} -e 's|defined(bsd) and not ||' \
		${WRKDIR}/${FPCSRCDIR}/rtl/unix/cwstring.pp
.endif

do-build:
# build fpc compiler
	(cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} cycle ${MAKE_ARGS} ${BOOTPPC})
# build fpcmkcfg
	(cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcm && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${NEWPPC})
	(cd ${WRKDIR}/${FPCSRCDIR}/packages/fcl-base && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${NEWPPC})
	(cd ${WRKDIR}/${FPCSRCDIR}/packages/fcl-process && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${NEWPPC})
	(cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcmkcfg && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${NEWPPC})

do-install:
# 	Installing fpc compiler
	(cd ${WRKDIR}/${FPCSRCDIR}/rtl && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} install ${MAKE_ARGS} ${NEWFPC})
# 	Installing fpc runtime
	(cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} install ${MAKE_ARGS} ${NEWFPC})
# 	Installng fpcmkcfg
	(cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcmkcfg && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} install ${MAKE_ARGS} ${NEWFPC})
# 	Installng fpcmake
	${INSTALL_PROGRAM} ${WRKDIR}/${FPCSRCDIR}/utils/fpcm/fpcmake \
		${STAGEDIR}${PREFIX}/bin
# 	Installing manpages
	${INSTALL_MAN} ${WRKDIR}/man/man1/* ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKDIR}/man/man5/* ${STAGEDIR}${MAN1PREFIX}/man/man5

post-install:
	if [ -e "${STAGEDIR}${PREFIX}/bin/${PPNAME}" ]; then ${RM} -f "${STAGEDIR}${PREFIX}/bin/${PPNAME}"; fi
	${LN} -sf "${PREFIX}/lib/fpc/${PORTVERSION}/${PPNAME}" "${STAGEDIR}${PREFIX}/bin"
	${SH} "${STAGEDIR}${PREFIX}/lib/fpc/${PORTVERSION}/samplecfg" "${STAGEDIR}${PREFIX}/lib/fpc/${PORTVERSION}" "${STAGEDIR}${PREFIX}/etc"
	@${REINPLACE_CMD} -i "" -e 's|${STAGEDIR}||' \
		-e 's|^-Fl/usr/local/lib|-Fl${LOCALBASE}/lib;${LOCALBASE}/lib/qt4|g' ${STAGEDIR}${PREFIX}/etc/fpc.cfg.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fpc*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mk*ins
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ppu*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/fpc/${PORTVERSION}/ppc*

.else
.include "${MASTERDIR}/Makefile.units"
.endif
.include <bsd.port.post.mk>

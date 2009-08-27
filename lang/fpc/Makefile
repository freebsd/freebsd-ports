# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTNAME=	fpc
PORTVERSION=	2.2.4
PORTREVISION?=	0
CATEGORIES?=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://planetmirror.com/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/${PORTVERSION}/source/:source \
		ftp://freepascal.stack.nl/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/${PORTVERSION}/source/:source \
		SF/freepascal/Source/${PORTVERSION}:source \
		${MASTER_SITE_GOOGLE_CODE}:bin \
		${MASTER_SITE_LOCAL:S|$|acm/freepascal/:bin|}
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME:S/$/.source/}${EXTRACT_SUFX}:source
DIST_SUBDIR=	freepascal

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	Free Pascal compiler with Turbo and Delphi

PROJECTHOST=	bsdistfiles
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
SUB_FILES=	pkg-message

OPT?=-CX
FPCSRCDIR=	${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if !defined(PKGNAMESUFFIX)
BUILDNAME=	${ARCH}-freebsd
PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		BUILDNAME=${BUILDNAME}
DISTFILES+=	${DISTNAME:S/$/.bin/}${EXTRACT_SUFX}:bin
MAKE_ENV+=	PP=${WRKDIR}/${PORTNAME}-${PORTVERSION:S/$/.bin/}/lib/${PORTNAME}/${PORTVERSION}/ppc386 \
		FPCMAKE=${WRKDIR}/${PORTNAME}-${PORTVERSION:S/$/.bin/}/bin/fpcmake \
		FPCTARGET=${BUILDNAME} \
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
	mkxmlrpc.1 \
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
	@${TAR} xfz ${_DISTDIR}/${DISTNAME:S/$/.bin/}${EXTRACT_SUFX} --directory \
		${WRKDIR}
# unpack source distribution
	@cd ${WRKDIR} && \
		${GZIP_CMD} -dc ${_DISTDIR}/${DISTNAME:S/$/.source/}${EXTRACT_SUFX} \
			| ${TAR} xf - ${FPCSRCDIR}/compiler ${FPCSRCDIR}/rtl ${FPCSRCDIR}/utils/fpcm

post-patch:
# patch fpc rtl
	@${REINPLACE_CMD} -i "" -e 's|504000|${OSVERSION}|g' ${WRKDIR}/${FPCSRCDIR}/rtl/freebsd/${ARCH}/cprt0.as

do-build:
# build fpc compiler
	@cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${GMAKE} cycle ${MAKE_ENV}
# build fpcmake
	@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcm && ${GMAKE} ${MAKE_ENV}

do-install:
	# Installing fpc compiler
	@cd ${WRKDIR}/${FPCSRCDIR}/rtl && ${GMAKE} install ${MAKE_ENV}
      	# Installing fpc runtime
	@cd ${WRKDIR}/${FPCSRCDIR}/compiler && ${GMAKE} install ${MAKE_ENV}
	# Installng fpcmake
	@@cd ${WRKDIR}/${FPCSRCDIR}/utils/fpcm && ${GMAKE} install ${MAKE_ENV}
	# Installing manpages
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION:S/$/.bin/}/man/man1/* ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-${PORTVERSION:S/$/.bin/}/man/man5/* ${MAN1PREFIX}/man/man5

post-install:
	if [ -e "${PREFIX}/bin/ppc386" ]; then ${RM} -f "${PREFIX}/bin/ppc386"; fi
	${LN} -s "${PREFIX}/lib/fpc/${PORTVERSION}/ppc386" "${PREFIX}/bin"
	${SH} "${PREFIX}/lib/fpc/${PORTVERSION}/samplecfg" "${PREFIX}/lib/fpc/${PORTVERSION}" "${PREFIX}/etc"
	@if [ ! -f ${PREFIX}/etc/fpc.cfg ]; then \
		${CP} ${PREFIX}/etc/fpc.cfg.sample ${PREFIX}/etc/fpc.cfg; \
	fi
	@${CAT} ${PKGMESSAGE}

.else
.include "${MASTERDIR}/Makefile.units"
.endif
.include <bsd.port.post.mk>

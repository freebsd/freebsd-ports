# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTNAME=	fpc
PORTVERSION=	2.0.2
CATEGORIES?=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://planetmirror.com/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/i386-freebsd-${PORTVERSION}/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
DISTNAME=	${PORTNAME}-${PORTVERSION}.${BUILDNAME}
EXTRACT_SUFX=	.tar

MAINTAINER?=	acardenas@bsd.org.pe
COMMENT?=	Free Pascal compiler with Turbo and Delphi

BUILDNAME=	i386-freebsd
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		BUILDNAME=${BUILDNAME}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if !defined(PKGNAMESUFFIX)
MAN1=	bin2obj.1 \
	data2inc.1 \
	delp.1 \
	fd2pascal.1 \
	fpc.1 \
	fpcmake.1 \
	fpdoc.1 \
	fprcp.1 \
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
	rstconv.1 \
	unitdiff.1
MAN5=	fpc.cfg.5 fpcmake.5 ptop.cfg.5

# only need misc/compat4x if using the pre-built ppc386
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif

do-extract:
# unpack distribution
	@${MKDIR} ${WRKSRC}
	@${TAR} xf ${DISTDIR}/${DISTNAME}.tar --directory ${WRKSRC}
# unpack pre-compiled binaries distribution
	@${MKDIR} ${WRKSRC}/binary
	@${TAR} xf ${WRKSRC}/binary.${BUILDNAME}.tar --directory ${WRKSRC}/binary
# create a local binary ppc386
	@${MKDIR} ${WRKSRC}/boot
	@${TAR} zxf ${WRKSRC}/binary/base.${BUILDNAME}.tar.gz \
		--directory ${WRKSRC}/boot
	@${TAR} zxf ${WRKSRC}/binary/utils.${BUILDNAME}.tar.gz \
		--directory ${WRKSRC}/boot

do-install:
	# Installing binaries
	${INSTALL_SCRIPT} ${WRKSRC}/boot/bin/* ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/boot/share/doc/fpc-${PORTVERSION}/* ${DOCSDIR}
.endif
	# Installing fpc libs
	${CP} -r ${WRKSRC}/boot/lib/* ${PREFIX}/lib
	# Installing manpages
	${INSTALL_DATA} ${WRKSRC}/boot/man/man1/* ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/boot/man/man5/* ${MAN1PREFIX}/man/man5

post-install:
	if [ -e "${PREFIX}/bin/ppc386" ]; then ${RM} -f "${PREFIX}/bin/ppc386"; fi
	${LN} -s "${PREFIX}/lib/fpc/${PORTVERSION}/ppc386" "${PREFIX}/bin"
	${SH} "${PREFIX}/lib/fpc/${PORTVERSION}/samplecfg" "${PREFIX}/lib/fpc/${PORTVERSION}" "${PREFIX}/etc"
	@${CAT} ${PKGMESSAGE}

.else
.include "${MASTERDIR}/Makefile.units"
.endif
.include <bsd.port.post.mk>

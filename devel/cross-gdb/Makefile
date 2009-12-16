# New ports collection makefile for:	cross-gdb
# Date created:		11 June 2007
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/releases
PKGNAMEPREFIX=	${TGTARCH}-${TGTABI}-

PATCH_SITES=	ftp://ftp.rtems.org/pub/rtems/SOURCES/4.10/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	stas@FreeBSD.org
COMMENT=	GNU gdb port for cross-target development

#
# Temporary hack to dial with dependencies during package builds for
# slave ports.
#
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS=	${OURTARGET}-as:${PORTSDIR}/devel/${OURTARGET}-binutils
.else
BUILD_DEPENDS=	${OURTARGET}-as:${PORTSDIR}/devel/cross-binutils
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	all info
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}{PORTNAME}

DEPENDS_ARGS=	TGTARCH="${TGTARCH}" TGTABI="${TGTABI}"

CONFIGURE_ARGS+=	--disable-nls \
			--exec-prefix=${EPRFX}/ \
			--target=${OURTARGET} \
			--with-python=no \
			--datadir="${DATADIR}"

OURTARGET=	${TGTARCH}-${TGTABI}

MAN1=		${OURTARGET}-gdb.1 \
		${OURTARGET}-gdbtui.1

INFO=		${OURTARGET}-annotate \
		${OURTARGET}-gdb \
		${OURTARGET}-gdbint \
		${OURTARGET}-stabs

EPRFX=		${PREFIX}/libexec/${OURTARGET}-gdb

.if defined(WITH_RTEMS_PATCHES)
PATCHFILES+=	${PORTNAME}-${PORTVERSION}-rtems4.10-20091007.diff
.endif

.if !defined(TGTARCH) || !defined(TGTABI)
PKGNAMEPREFIX=	cross-
OURTARGET=	cross	# to generate correct dependency list
IGNORE=		you should define TGTARCH and TGTABI to build port
.endif

#
# Macro to fix up info referencies
#
FIXREFS=	${SH} -c '${REINPLACE_CMD} -E \
		-e "s,$$0\.(texi|info),${OURTARGET}-$$0.\1,g" \
		-e "s,(@file)\{$$0\},\1\{${OURTARGET}-$$0\},g" $$*' --

post-patch:
#
# Patch and rename info files
#
.for FILE in annotate gdb gdbint stabs
	@${FIXREFS} ${FILE} ${WRKSRC}/gdb/doc/${FILE}.texinfo \
		${WRKSRC}/gdb/doc/Makefile.in
	@${MV} ${WRKSRC}/gdb/doc/${FILE}.texinfo \
		${WRKSRC}/gdb/doc/${OURTARGET}-${FILE}.texinfo
.endfor

# Don't install run.1 manpage, we'll install it by hand
	@${REINPLACE_CMD} -E -e 's,^(install:)[[:space:]]+install-man,\1,' \
		${WRKSRC}/sim/common/Makefile.in

#
# Don't install certain infofiles
#
	@${REINPLACE_CMD} -E -e 's,^(install:).*,\1,' \
		${WRKSRC}/etc/Makefile.in \
		${WRKSRC}/bfd/doc/Makefile.in

post-install:
#
# Install handy symlinks
#
	@${LN} -sf ${EPRFX}/bin/${OURTARGET}-gdb ${PREFIX}/bin/${OURTARGET}-gdb
	@${ECHO} "@exec ${LN} -sf ${EPRFX}/bin/${OURTARGET}-gdb " \
		"${PREFIX}/bin/${OURTARGET}-gdb" >> ${TMPPLIST}
	@${ECHO} "@unexec ${RM} -f ${PREFIX}/bin/${OURTARGET}-gdb" \
		>> ${TMPPLIST}

#
# Install link for emulator if exists
#
	@if [ -e "${EPRFX}/bin/${OURTARGET}-run" ]; then \
		${LN} -sf ${EPRFX}/bin/${OURTARGET}-run \
			${PREFIX}/bin/${OURTARGET}-run && \
		${ECHO} "@exec ${LN} -sf ${EPRFX}/bin/${OURTARGET}-run " \
			"${PREFIX}/bin/${OURTARGET}-run" >> ${TMPPLIST} && \
		${ECHO} "@unexec ${RM} -f ${PREFIX}/bin/${OURTARGET}-run" \
			>> ${TMPPLIST}; \
	fi

#
# Generate packing list
#
	@${FIND} ${EPRFX}/ ! -type d | ${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${EPRFX}/ -type d | \
		${SED} -E -e 's,(.*),@unexec rmdir \1 2>/dev/null || true,' >> \
		${TMPPLIST}
	@${FIND} ${DATADIR}/ ! -type d | ${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${DATADIR}/ -type d | \
		${SED} -E -e 's,(.*),@unexec rmdir \1 2>/dev/null || true,' >> \
		${TMPPLIST}

.include <bsd.port.mk>

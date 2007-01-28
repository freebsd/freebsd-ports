# New ports collection makefile for: djgpp-binutils
# Date created:		27 Jan 2007
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	${BINUTILVERSION}.${PATCHVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	djgpp-
DISTNAME=	${PORTNAME}-${BINUTILVERSION}.${PATCHVERSION}

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	FSF binutils-2.16 for DJGPP cross-development

BINUTILVERSION=	2.16
PATCHVERSION=	1

TARGET=		i586-pc-msdosdjgpp

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure

#USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
SRCDIR=		${WRKDIR}/binutils-${BINUTILVERSION}.${PATCHVERSION}
WRKSRC=		${WRKDIR}/build
CONFIGURE_ARGS=	--target=${TARGET} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-shared \
		--infodir=${PREFIX}/${TARGET}/info

MAN1=	${TARGET}-addr2line.1 ${TARGET}-ar.1    \
	${TARGET}-as.1 ${TARGET}-dlltool.1      \
	${TARGET}-c++filt.1 ${TARGET}-ld.1      \
	${TARGET}-nlmconv.1 ${TARGET}-nm.1      \
	${TARGET}-objcopy.1 ${TARGET}-objdump.1 \
	${TARGET}-ranlib.1 ${TARGET}-readelf.1  \
	${TARGET}-size.1 ${TARGET}-strings.1    \
	${TARGET}-strip.1 ${TARGET}-windres.1

INFO=		as bfd binutils ld configure standards
INFO_PATH=	${TARGET}/info

BINARIES=	addr2line ar as c++filt ld nm objcopy objdump ranlib \
		readelf size strings strip

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${TARGET}-$F ${PREFIX}/${TARGET}/bin/$F
.endfor

#
# UGLY HACK
#
add-plist-post:
	@${ECHO_CMD} "@unexec rmdir -p %D/${TARGET}/info 2> /dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir -p %D/${TARGET} 2> /dev/null || true" >> ${TMPPLIST}
.if (defined(PREFIX) && ${PREFIX} != ${LOCALBASE} && ${PREFIX} != ${X11BASE} && ${PREFIX} != ${LINUXBASE} && ${PREFIX} != "/usr")
	@${ECHO_CMD} "@unexec rmdir %D 2> /dev/null || true" >> ${TMPPLIST}
.else
	@${DO_NADA}
.endif

.include <bsd.port.mk>

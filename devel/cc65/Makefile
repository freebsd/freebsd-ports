# Ports collection makefile for:	cc65
# Date created:			8 May 2000
# Whom:				Tim Vanderhoek <hoek@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cc65
PORTVERSION=	2.10.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.musoftware.de/pub/uz/cc65/ \
		http://www.funet.fi/pub/cbm/programming/cc65/ \
		http://www.acc.umu.se/~arvid/cc65_mirror/ \
		http://bj.spline.de/cc65/
# This mirror seems to stop at version 2.7.0
#		ftp://ftp.elysium.pl/tools/crossplatform/programming/c/cc65/ \
DISTNAME=	${PORTNAME}-sources-${PORTVERSION}

MAINTAINER=	watchman@ludd.ltu.se
COMMENT=	Cross-compiler for 6502-based systems, includes 65816 assembler

USE_SUBMAKE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
CFLAGS+=	-DCC65_INC=\\\"${PREFIX}/lib/cc65/include\\\" \
		-DCC65_LIB=\\\"${PREFIX}/lib/cc65/lib\\\" \
		-I${WRKSRC}/src/common -Wall -W -DSPAWN_UNIX

# Need ${WRKSRC} so that the (slightly ugly) != assignments work
.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

WRKSRC=		${WRKDIR}/cc65-${PORTVERSION}

DEVNULL=	${__empty_string_for_portlint}/dev/null

# These doc files can be compiled using the textproc/sgmltools port
# XXX sgmltools port was removed, perhaps something else can be
# used instead
DOCFILES!=	${LS} ${WRKSRC}/doc 2> ${DEVNULL} | \
		    ${SED} -E -e 's/^/doc\//' && ${ECHO_CMD} announce.txt

BINFILES= \
	src/ar65/ar65 src/ca65/ca65 src/cc65/cc65 \
	src/cl65/cl65 src/da65/da65 src/grc/grc src/ld65/ld65 src/od65/od65

BINSCRIPTS= src/ca65html/ca65html

ASMINCFILES!=	${LS} ${WRKSRC}/asminc 2> ${DEVNULL} | ${EGREP} '\.inc' || true

CC65LIBFILES!=	${LS} ${WRKSRC}/libsrc/ 2> ${DEVNULL} | ${EGREP} '\.(o|lib)' \
		    || true

CC65EMDFILES!=	${LS} ${WRKSRC}/libsrc/ 2> ${DEVNULL} | ${EGREP} '\.emd' || true

CC65TGIFILES!=	${LS} ${WRKSRC}/libsrc/ 2> ${DEVNULL} | ${EGREP} '\.tgi' || true

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} -ef make/gcc.mak
	cd ${WRKSRC}/libsrc && ${GMAKE} all

do-install:
	${MKDIR} ${PREFIX}/lib/cc65/emd
	${MKDIR} ${PREFIX}/lib/cc65/lib
	${MKDIR} ${PREFIX}/lib/cc65/tgi
	${MKDIR} ${PREFIX}/lib/cc65/asminc
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cc65
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${PREFIX}/share/doc/cc65
	${CP} -R ${WRKSRC}/samples ${PREFIX}/share/doc/cc65
	${FIND} ${PREFIX}/share/doc/cc65/samples -not -type d | \
	    ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/share/doc/cc65/samples -not -type d | \
	    ${XARGS} ${CHMOD} ${SHAREMODE}
.endif
	${INSTALL_PROGRAM} ${BINFILES:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${BINSCRIPTS:S,^,${WRKSRC}/,} ${PREFIX}/bin
	${INSTALL_DATA} ${ASMINCFILES:S,^,${WRKSRC}/asminc/,} \
	    ${PREFIX}/lib/cc65/asminc
	${CP} -R ${WRKSRC}/include ${PREFIX}/lib/cc65
	${FIND} ${PREFIX}/lib/cc65 -not -type d | \
	    ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${PREFIX}/lib/cc65 -not -type d | \
	    ${XARGS} ${CHMOD} ${SHAREMODE}
	${INSTALL_DATA} ${CC65LIBFILES:S,^,${WRKSRC}/libsrc/,} \
	    ${PREFIX}/lib/cc65/lib
	${INSTALL_DATA} ${CC65EMDFILES:S,^,${WRKSRC}/libsrc/,} \
	    ${PREFIX}/lib/cc65/emd
	${INSTALL_DATA} ${CC65TGIFILES:S,^,${WRKSRC}/libsrc/,} \
	    ${PREFIX}/lib/cc65/tgi

plist:
	@${FIND} ${WRKSRC}/samples -not -type d | \
	    ${SED} -E -e 's/^.*cc65.*\/samples/%%PORTDOCS%%share\/doc\/cc65\/samples/'
	@${FIND} ${WRKSRC}/samples -type d | ${SORT} -r | \
	    ${SED} -E -e 's/^.*cc65.*\/samples/%%PORTDOCS%%@dirrm share\/doc\/cc65\/samples/'
.for filename in ${DOCFILES}
	@${ECHO_CMD} %%PORTDOCS%%share/doc/cc65/`${BASENAME} ${filename}`
.endfor
	@${ECHO_CMD} %%PORTDOCS%%@dirrm share/doc/cc65
.for filename in ${BINFILES}
	@${ECHO_CMD} bin/`${BASENAME} ${filename}`
.endfor
.for filename in ${BINSCRIPTS}
	@${ECHO_CMD} bin/`${BASENAME} ${filename}`
.endfor
.for filename in ${ASMINCFILES}
	@${ECHO_CMD} lib/cc65/asminc/`${BASENAME} ${filename}`
.endfor
	@${FIND} ${WRKSRC}/include -not -type d | \
	    ${SED} -E -e 's/^.*cc65.*\/include/lib\/cc65\/include/'
	@${FIND} ${WRKSRC}/include -type d | ${SORT} -r | \
	    ${SED} -E -e 's/^.*cc65.*\/include/@dirrm lib\/cc65\/include/'
.for filename in ${CC65LIBFILES}
	@${ECHO_CMD} lib/cc65/lib/`${BASENAME} ${filename}`
.endfor
.for filename in ${CC65EMDFILES}
	@${ECHO_CMD} lib/cc65/emd/`${BASENAME} ${filename}`
.endfor
.for filename in ${CC65TGIFILES}
	@${ECHO_CMD} lib/cc65/tgi/`${BASENAME} ${filename}`
.endfor
	@${ECHO_CMD} @dirrm lib/cc65/emd
	@${ECHO_CMD} @dirrm lib/cc65/lib
	@${ECHO_CMD} @dirrm lib/cc65/tgi
	@${ECHO_CMD} @dirrm lib/cc65/asminc
	@${ECHO_CMD} @dirrm lib/cc65

.include <bsd.port.post.mk>

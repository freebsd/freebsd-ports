# New ports collection makefile for:	Free Pascal Compiler
# Date created: 			28 November 2001
# Whom: 				John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTNAME=	fpc
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/FreeBSD/ \
		http://planetmirror.com/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/FreeBSD/ \
		ftp://freepascal.stack.nl/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/FreeBSD/ \
		ftp://ftp.us.freepascal.org/pub/fpc/dist/FreeBSD/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepascal
DISTNAME=	${PORTNAME}-${PORTVERSION}.ELF
EXTRACT_SUFX=	.tar

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Free Pascal compiler with Turbo, Delphi and other extensions

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Install fails"
.endif

LIB_DEPENDS=	gds.1:${PORTSDIR}/databases/firebird
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=   c.4:${PORTSDIR}/misc/compat4x
.endif
.if ${OSVERSION} < 470000
EXTRACT_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar
TAR=			${LOCALBASE}/bin/gtar
.endif
USE_MYSQL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386
PKGDEINSTALL=	${PKGINSTALL}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=	delp.1 fpc.1 fpcmake.1 fpdoc.1 h2pas.1 plex.1 ppc386.1 ppdep.1 \
	ppudump.1 ppufiles.1 ppumove.1 ptop.1 pyacc.1 rstconv.1
MAN5=	fpc.cfg.5 fpcmake.5 ptop.cfg.5

# FreePascal is not self-bootstrapping.  Hence, the need for a working
# pppc386.  Check for ppc386 in a manner similar to lang/gnat.
#
# Look in PREFIX
.ifdef PREFIX
have_boot!=	if [ -x ${PREFIX}/bin/ppc386 ]; then \
			${ECHO_CMD} "${PREFIX}/bin"; \
		else \
			${ECHO_CMD} ""; \
		fi
.else
have_boot=
.endif

# Then look in LOCALBASE
.if empty(have_boot)
have_boot!=	if [ -x ${LOCALBASE}/bin/ppc386 ]; then \
			${ECHO_CMD} "${LOCALBASE}/bin"; \
		else \
			${ECHO_CMD} ""; \
		fi
.endif

.if empty(have_boot)
have_boot=	${WRKSRC}/boot
.endif

MAKE_ENV+=	PATH=${have_boot}/bin:$$PATH \
		FPC=${have_boot}/bin/ppc386 \
		INSTALL_BASEDIR=${PREFIX}/lib/fpc/${PORTVERSION} \
		INSTALL_BINDIR=${PREFIX}/bin \
		GCCLIBDIR=/usr/lib \
		RELEASE=1

do-extract:
# unpack distribution
	@${MKDIR} ${WRKSRC}
	@${TAR} xf ${DISTDIR}/${DISTNAME}.tar --directory ${WRKSRC}
# unpack pre-compiled binaries distribution
	@${MKDIR} ${WRKSRC}/binary
	@${TAR} xf ${WRKSRC}/binary.tar --directory ${WRKSRC}/binary
# unpack sources distribution
	@${MKDIR} ${WRKSRC}/sources
	@${TAR} xf ${WRKSRC}/sources.tar --directory ${WRKSRC}/sources
# create a local binary ppc386
	@${MKDIR} ${WRKSRC}/boot
	@${TAR} zxf ${WRKSRC}/binary/basefreebsd.tar.gz \
		--directory ${WRKSRC}/boot
	@${TAR} zxf ${WRKSRC}/binary/utilfreebsd.tar.gz \
		--directory ${WRKSRC}/boot
	@${LN} -sf ${WRKSRC}/boot/lib/fpc/${PORTVERSION}/ppc386 \
		${WRKSRC}/boot/bin/ppc386
# further extract base sources
#
# mandatory sources
	@${TAR} zxf ${WRKSRC}/sources/basesrc.tar.gz \
		--directory ${WRKSRC}
	@${TAR} zxf ${WRKSRC}/sources/compilersrc.tar.gz \
		--directory ${WRKSRC}
	@${TAR} zxf ${WRKSRC}/sources/rtlsrc.tar.gz \
		--directory ${WRKSRC}
# dependencies of FCL
	@${TAR} zxf ${WRKSRC}/sources/unitspaszlibsrc.tar.gz \
		--directory ${WRKSRC}
	@${TAR} zxf ${WRKSRC}/sources/unitsnetdbsrc.tar.gz \
		--directory ${WRKSRC}
	@${TAR} zxf ${WRKSRC}/sources/unitslibasyncsrc.tar.gz \
		--directory ${WRKSRC}
	@${TAR} zxf ${WRKSRC}/sources/unitsmysqlsrc.tar.gz \
		--directory ${WRKSRC}
	@${TAR} zxf ${WRKSRC}/sources/unitsibasesrc.tar.gz \
		--directory ${WRKSRC}
# FCL is required for some of the compiler utilities
	@${TAR} zxf ${WRKSRC}/sources/fclsrc.tar.gz \
		--directory ${WRKSRC}
# compiler utilities
	@${TAR} zxf ${WRKSRC}/sources/utilssrc.tar.gz \
		--directory ${WRKSRC}

post-patch:
# change to alter amount of optimization
	@${FIND} ${WRKSRC}/share/src/fpc-${PORTVERSION} -name \
		"Makefile*" | ${XARGS} ${REINPLACE_CMD} 's|-OG2p3|-OG2p1|g'

do-build:
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/rtl && \
		${GMAKE} ${MAKE_ENV} all
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/compiler && \
		${GMAKE} ${MAKE_ENV} all
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/libasync && \
		${GMAKE} ${MAKE_ENV} all
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/fcl && \
		${GMAKE} ${MAKE_ENV} all
# kludge so that bin2obj finds ZSTREAM and builds
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION} && \
		${CP} fcl/inc/zstream.pp utils
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/utils && \
		${GMAKE} ${MAKE_ENV} all

do-install:
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/rtl && \
		${GMAKE} ${MAKE_ENV} install
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/compiler && \
		${GMAKE} ${MAKE_ENV} install
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/packages/base/libasync && \
		${GMAKE} ${MAKE_ENV} install
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/fcl && \
		${GMAKE} ${MAKE_ENV} install
	cd ${WRKSRC}/share/src/fpc-${PORTVERSION}/utils && \
		${GMAKE} ${MAKE_ENV} install
	@${MKDIR} ${PREFIX}/man/man1
	cd ${WRKSRC}/boot/man/man1 && ${INSTALL_MAN} ${MAN1} \
		${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/man/man5
	cd ${WRKSRC}/boot/man/man5 && ${INSTALL_MAN} ${MAN5} \
		${PREFIX}/man/man5

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>

# New ports collection makefile for:	fpc-devel		(Free Pascal 1.9.x beta series)
# Date created:		21 Mar 2004
# Whom:			Marco van de Voort, Marco@freepascal.org
#
# $FreeBSD$
#

PORTNAME=	fpc-devel
PORTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://freepascal.stack.nl/pub/fpc/beta/freebsd-${PORTVERSION}-ports/  \
		ftp://ftp.freepascal.org/pub/fpc/beta/freebsd-${PORTVERSION}-ports/
DISTNAME=	fpc-${PORTVERSION}-ports
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	marco@freepascal.org
COMMENT=	Delphi and Turbo Pascal compatible Pascal (commandline) compiler

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

.include <bsd.port.pre.mk>

USE_GMAKE=	yes
USE_BZIP2=	yes

PLIST_SUB+=	FPC_VERSION=${PORTVERSION}
PLIST_SUB+=     PORTVERSION="${PORTVERSION}"

MAN1=		delp.1 fpc.1 fpcmake.1 fpdoc.1 h2pas.1 plex.1 ppc386.1 ppdep.1 \
		ppudump.1 ppufiles.1 ppumove.1 ptop.1 pyacc.1 rstconv.1
MAN5=		fpc.cfg.5 fpcmake.5 ptop.cfg.5

NO_WRKSUBDIR=	yes

# Sparc, PowerPC expected mid-longterm

ONLY_FOR_ARCHS=	i386

# Note that if there are $VERSION and $TARGET in -F<x> Lines, then they  are _not_ typo's,
# but fpc.cfg syntax.

do-build:
	${GMAKE} -C ${WRKDIR}/fpc all PP=${WRKDIR}/cmdlinecomp/ppc386-${PORTVERSION}-i386
	${ECHO} '-Fu${PREFIX}/lib/fpc/${PORTVERSION}/units/freebsd/*' >> ${WRKDIR}/fpc.cfg
	${ECHO} '-Fu${PREFIX}/lib/fpc/${PORTVERSION}/units/freebsd/rtl' >> ${WRKDIR}/fpc.cfg
	${ECHO} '-Fl${PREFIX}/lib' >> ${WRKDIR}/fpc.cfg

do-install:
	${GMAKE} -C ${WRKDIR}/fpc install \
	PP=${WRKDIR}/fpc/compiler/ppc386 INSTALL_PREFIX=${PREFIX}

# Note: symlink creation must be fixed for other archs! Needs possibly GNU arch vs FPC arch conversion.
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/fpc-${PORTVERSION}
	@${INSTALL_MAN} ${WRKDIR}/docs/*.pdf ${PREFIX}/share/doc/fpc-${PORTVERSION}
#	${CAT} ${FILESDIR}/srcfiles | ${XARGS} -n 1 -I RePl ${INSTALL_MAN} ${WRKDIR}/fpc/RePl ${PREFIX}/src/fpc-${PORTVERSION}
	@for i in `cat ${FILESDIR}/srcfiles`; do ${INSTALL} -d `dirname ${PREFIX}/src/fpc-${PORTVERSION}/$$i`; ${INSTALL_MAN} ${WRKDIR}/fpc/$$i ${PREFIX}/src/fpc-${PORTVERSION}/$$i  ;done;
.endif
	@${LN} -s ${PREFIX}/lib/fpc/${PORTVERSION}/ppc386 ${PREFIX}/bin/ppc386
# Only possible locations (at this moment): /etc/fpc.cfg  $prefix/bin/fpc.cfg and ~/.fpc.cfg
# What INSTALL_ is needed for a config file anyway?
.if ${PREFIX} == "/usr"
	@${INSTALL_MAN} ${WRKDIR}/fpc.cfg /etc/fpc.cfg.sample
.else
	@${INSTALL_MAN} -v ${WRKDIR}/fpc.cfg ${HOME}/.fpc.cfg.sample
.endif
	@${CAT} pkg-message

.include <bsd.port.post.mk>

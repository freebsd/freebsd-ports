# New ports collection makefile for:	gaussian98
# Date created:		Feb 10 2001
# Whom:			NAKATA, Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	gaussian98
PORTVERSION=	1.0.7
CATEGORIES=	biology
MASTER_SITES=	file:${CD_MOUNTPT}/TAR/
DISTNAME=	WKSSRC
EXTRACT_SUFX=	.TAR

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

LIB_DEPENDS=	blas:${PORTSDIR}/math/blas

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/g98

NO_CDROM=	"You must purchase a licensed copy from Gaussian inc."
NO_PACKAGE=	"You must purchase a licensed copy from Gaussian inc."
RESTRICTED=	"You must purchase a licensed copy from Gaussian inc."

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400013
F77?=		g77
.else
F77?=		f77
.endif

post-extract:
	${RM} ${DISTDIR}/${DISTFILES}

post-patch:
	@${SED} -e s+@PREFIX@+${PREFIX}+ ${FILESDIR}/gaussian98  > ${WRKSRC}/gaussian98
	@${ECHO} "You can override and FFLAGS on the command line."
	@${ECHO} "Following is an recommended one."
	@${ECHO} "make FFLAGS=\"-malign-double -fexpensive-optimizations -O4 -ffast-math -funroll-loops\""

MAKE_ENV=	"GMAKE=${GMAKE} F77=${F77} PREFIX=${PREFIX}"

do-build:
	(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} csh ./bsd/bldg98)

do-install:
	@${MKDIR} ${PREFIX}/bin/g98/bsd \
	 	  ${PREFIX}/share/gaussian98/explore/examples \
	 	  ${PREFIX}/share/gaussian98/explore/exercise \
		  ${PREFIX}/share/gaussian98/explore/quick
	@(cd ${WRKSRC}/bsd; \
	  ${INSTALL_SCRIPT} gau-unlimit set-mflags g98.login \
		${PREFIX}/bin/g98/bsd; \
	  cd ${WRKSRC}; \
	  ${INSTALL_PROGRAM} gauopt ghelp newzmat testrt cubegen cubman \
		c8698 ham506 cktoig rwfdump chkmove freqchk freqmem formchk \
		demofc chkchk pluck unfchk g98 *.exe gau-machine \
		${PREFIX}/bin/g98; \
	  ${INSTALL_SCRIPT} gaussian98 ${PREFIX}/bin; \
	  ${INSTALL_DATA} ${WRKSRC}/libgauutil.so.1 ${PREFIX}/lib; \
	  cd ${PREFIX}/lib; ${LN} -sf libgauutil.so.1 libgauutil.so; \
	  cd ${WRKSRC}/explore/examples; \
	  ${INSTALL_DATA} * ${PREFIX}/share/gaussian98/explore/examples; \
	  cd ${WRKSRC}/explore/exercise; \
	  ${INSTALL_DATA} *  ${PREFIX}/share/gaussian98/explore/exercise; \
	  cd ${WRKSRC}/explore/quick; \
	  ${INSTALL_DATA} * ${PREFIX}/share/gaussian98/explore/quick)

.include <bsd.port.post.mk>

# New ports collection makefile for:    crossgo32
# Version required:     1.3
# Date created:         6 Mar 97
# Whom:                 Pedro Giffuni <giffunip@asme.org>
# Date updated: 	Sun Jun 22 16:11:40 EST 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $FreeBSD$
#

DISTNAME=	crosstree-1.3
PKGNAME=	crossgo32-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.cygnus.com/pub/embedded/crossgcc/

MAINTAINER=	sutton@aardvark.apana.org.au

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} dosrel-1.0${EXTRACT_SUFX}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --target=${TARGET}
USE_GMAKE=	yes
TARGET= 	i386-go32

MAN1=	i386-go32-ar.1 i386-go32-nm.1 i386-go32-objdump.1\
	i386-go32-ranlib.1 i386-go32-size.1 i386-go32-strings.1\
	i386-go32-strip.1 i386-go32-objcopy.1 i386-go32-nlmconv.1\
	i386-go32-g++.1 i386-go32-gcc.1 cccp.1\
	i386-go32-c++filt.1 configure.1 i386-go32-as.1 i386-go32-ld.1

DOCDIR=	${PREFIX}/share/doc/crossgo32
GO32DIR=${PREFIX}/share/crossgo32

post-extract:
	${MV} ${WRKDIR}/dosrel-1.0/ ${WRKSRC}

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/dosrel-1.0/

post-build:
	@cd ${WRKSRC}/dosrel-1.0 ;\
	 make coff2exe

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dosrel-1.0/coff2exe \
		${PREFIX}/bin/i386-go32-coff2exe
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documentation into ${DOCDIR}"
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ-0.8 ${DOCDIR}/
	${INSTALL_DATA} ${PKGDIR}/DESCR ${DOCDIR}/Readme.FreeBSD
.endif
	@${ECHO_MSG} "===>  Installing DJGPP exe files into ${GO32DIR}"
	${MKDIR} ${GO32DIR}
	${INSTALL_DATA} ${WRKSRC}/dosrel-1.0/go32.exe ${GO32DIR}/
	${INSTALL_DATA} ${WRKSRC}/dosrel-1.0/emu387 ${GO32DIR}/

.include <bsd.port.mk>

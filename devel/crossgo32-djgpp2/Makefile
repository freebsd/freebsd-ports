# New ports collection makefile for: djgpp2 cross compiler kit
# Version required:	2.01
# Date created:		Sun Jun 22 16:57:39 EST 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
# FreeBSD Version:	2.2.1-RELEASE
#
# $Id: Makefile,v 1.4 1998/11/08 08:44:59 asami Exp $
#

DISTNAME=	djcrx201
PKGNAME=	crossgo32-djgpp2-2.01
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.tas.gov.au/pc/simtelnet/gnu/djgpp/v2/ \
		ftp://ftp.cdrom.com/pub/simtelnet/gnu/djgpp/v2/
EXTRACT_SUFX=	.zip

MAINTAINER=	sutton@aardvark.apana.org.au

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=	i386-go32-gcc:${PORTSDIR}/devel/crossgo32

BROKEN=		install

EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-La
EXTRACT_AFTER_ARGS=	# empty

# Source directories
#
NO_WRKSUBDIR=	yes
DJGPPLIB=	${WRKSRC}/lib
DJGPPINCLUDE=	${WRKSRC}/include
DJGPPDOC=	${WRKSRC}/cross
DJGPPINFO=	${WRKSRC}/info
STUBSRC=	${WRKSRC}/src/stub

# Install directories
#
DOCDIR=		${PREFIX}/share/doc/djgpp2
CROSSGO=	${PREFIX}/i386-go32
CROSSGOGCC=	${PREFIX}/lib/gcc-lib/i386-go32/2.7.2.2/
CROSSGOLIB=	${PREFIX}/i386-go32/lib
CROSSGOINCLUDE=	${PREFIX}/i386-go32/include

post-extract:
	${CP} ${FILESDIR}/Makefile ${STUBSRC}/

post-patch:
	-${RM} ${DJGPPLIB}/*.orig

do-build:
	@${ECHO_MSG} "===>  Building stub utilities"
	@cd ${STUBSRC} ;\
	 make all

pre-install:
	@${ECHO_MSG} "===>  Moving old crossgo libs away"
	@cd ${CROSSGO} ;\
	 ${MV} lib lib-newlib ;\
	 ${MV} include include-newlib
	@cd ${CROSSGOGCC} ;\
	 ${MKDIR} old-newlib ;\
	 ${MV} include old-newlib ;\
	 ${MV} libgcc.a old-newlib ;\
	 ${MV} specs old-newlib ;\

do-install:
	@${ECHO_MSG} "===>  Installing binaries"
	${INSTALL_PROGRAM} ${STUBSRC}/stubify ${PREFIX}/bin/i386-go32-stubify
	${INSTALL_PROGRAM} ${STUBSRC}/stubedit ${PREFIX}/bin/i386-go32-stubedit

	@${ECHO_MSG} "===>  Installing libraries"
	${CP} -R ${DJGPPLIB} ${CROSSGOLIB}

	@${ECHO_MSG} "===>  Installing include files"
	${CP} -R ${DJGPPINCLUDE} ${CROSSGOINCLUDE}

	@${ECHO_MSG} "===>  Installing info files"
	${INSTALL_DATA} ${DJGPPINFO}/libc.inf ${PREFIX}/info/libc.info

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documentation into ${DOCDIR}"
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${DJGPPDOC}/install ${DOCDIR}/
	${INSTALL_DATA} ${DJGPPDOC}/readme ${DOCDIR}/
	${INSTALL_DATA} ${PKGDIR}/DESCR ${DOCDIR}/Readme.FreeBSD
.endif

.include <bsd.port.mk>

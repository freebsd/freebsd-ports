# New ports collection makefile for:	djgpp2 cross compiler kit
# Date created:		Sun Jun 22 16:57:39 EST 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	crossgo32-djgpp2
PORTVERSION=	2.01
CATEGORIES=	devel
MASTER_SITES=	http://safariexamples.informit.com/0672322242/Software/DJGPP/v2/old/
DISTNAME=	djcrx201

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DJGPP V2 libraries and compatability for crossgo32 crosscompiler

BUILD_DEPENDS=	i386-go32-gcc:${PORTSDIR}/devel/crossgo32
RUN_DEPENDS=	i386-go32-gcc:${PORTSDIR}/devel/crossgo32

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-qLa

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
	 ${MAKE} all

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
	${INSTALL_DATA} ${DESCR} ${DOCDIR}/README.FreeBSD
.endif

.include <bsd.port.mk>

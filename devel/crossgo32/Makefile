# New ports collection makefile for:	crossgo32
# Date created:		6 Mar 97
# Whom:			Pedro Giffuni <giffunip@asme.org>
# Date updated: 	Sun Jun 22 16:11:40 EST 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	crossgo32
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://sources.redhat.com/pub/crossgcc/
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	crosstree-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} dosrel-1.0${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross Development Environment for 32-bit DOS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${TARGET}
USE_GMAKE=	yes
TARGET=	i386-go32
ONLY_FOR_ARCHS=	i386

MAN1=	i386-go32-ar.1 i386-go32-nm.1 i386-go32-objdump.1\
	i386-go32-ranlib.1 i386-go32-size.1 i386-go32-strings.1\
	i386-go32-strip.1 i386-go32-objcopy.1 i386-go32-nlmconv.1\
	i386-go32-g++.1 i386-go32-gcc.1 cccp.1\
	i386-go32-c++filt.1 configure.1 i386-go32-as.1 i386-go32-ld.1

DOCDIR=		${PREFIX}/share/doc/crossgo32
GO32DIR=	${PREFIX}/share/crossgo32

post-extract:
	${MV} ${WRKDIR}/dosrel-1.0/ ${WRKSRC}

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/dosrel-1.0/

post-build:
	@cd ${WRKSRC}/dosrel-1.0 ;\
	 ${MAKE} coff2exe

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dosrel-1.0/coff2exe \
		${PREFIX}/bin/i386-go32-coff2exe
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing documentation into ${DOCDIR}"
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ-0.8 ${DOCDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${DOCDIR}
.endif
	@${ECHO_MSG} "===>  Installing DJGPP exe files into ${GO32DIR}"
	${MKDIR} ${GO32DIR}
	${INSTALL_DATA} ${WRKSRC}/dosrel-1.0/go32.exe ${GO32DIR}
	${INSTALL_DATA} ${WRKSRC}/dosrel-1.0/emu387 ${GO32DIR}

.include <bsd.port.mk>

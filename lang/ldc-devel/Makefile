# New ports collection makefile for:	ldc
# Date created:				August 18 2010
# Whom:					Ruben <chromium@hybridsource.org>
#
# $FreeBSD$
#

PORTNAME=	ldc
DISTVERSION=	0.9.2r1697
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://hybridsource.org/
PKGNAMESUFFIX=	-devel
DISTFILES=	ldc-0.9.2r1697.tar.bz2 tango-5599.tar.bz2

MAINTAINER=	cy@FreeBSD.org
COMMENT=	D frontend for llvm, with the Tango standard library

BUILD_DEPENDS=	llvm>=2.8:${PORTSDIR}/devel/llvm
LIB_DEPENDS=	config.10:${PORTSDIR}/devel/libconfig

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-08-27

BROKEN=		does not compile

LICENSE_COMB=	multi
LICENSE=	BSD ART10
ONLY_FOR_ARCHS=	i386 amd64
USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USES=		cmake
MAKE_JOBS_SAFE=	yes
PORTDOCS=	LICENSE readme.txt tango/

.include <bsd.port.pre.mk>

MODULEDIR=	${PREFIX}/include/d/tango

.if ${ARCH} == i386
BOB=	build/bin/freebsd32/bob
.elif ${ARCH} == amd64
BOB=	build/bin/freebsd64/bob
.else #This won't actually be invoked but I thought I'd show
      #the adventurous how to build Tango on other architectures.
BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby18
BOB=		build/script/bob.rb
.endif

post-build:
	cd ${WRKSRC}/../tango && \
		${SETENV} PATH=${PATH}:${WRKSRC}/bin ./${BOB} -vu -r ldc -c ldc .
	@${REINPLACE_CMD} -e "s|${WRKSRC}/../tango|${MODULEDIR}|" \
	                  -e "s|-user-ldc||" ${WRKSRC}/bin/ldc.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ldc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ldmd ${PREFIX}/bin
.if !exists(${PREFIX}/etc/ldc.conf)
	${INSTALL_DATA} ${WRKSRC}/bin/ldc.conf ${PREFIX}/etc
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/ldc.conf ${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/../tango/libtango.a ${PREFIX}/lib
	${MKDIR} ${MODULEDIR}
	${INSTALL_DATA} ${WRKSRC}/../tango/object.di ${MODULEDIR}
	cd ${WRKSRC}/../tango && ${COPYTREE_SHARE} tango ${MODULEDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/tango
	${INSTALL_DATA} ${WRKSRC}/../tango/LICENSE.txt ${DOCSDIR}/tango
	${INSTALL_DATA} ${WRKSRC}/../tango/README.txt ${DOCSDIR}/tango
	cd ${WRKSRC}/../tango && ${COPYTREE_SHARE} doc ${DOCSDIR}/tango
.endif

.include <bsd.port.post.mk>

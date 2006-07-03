# New ports collection makefile for:	gpc
# Date created:				28 Jun 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	gpc
PORTVERSION=	20050331
CATEGORIES=	lang
MASTER_SITES=	http://www.gnu-pascal.de/alpha/:gpc \
		${MASTER_SITE_GCC}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gpc \
		gcc-core-${GCC_VERSION}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	GNU Pascal compiler

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		help2man:${PORTSDIR}/misc/help2man

USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
#USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-nls --enable-languages=pascal
WRKSRC=		${WRKDIR}/gcc-${GCC_VERSION}
INSTALL_WRKSRC=	${WRKSRC}/gcc
INSTALL_TARGET=	pascal.install

MAN1=		binobj.1 gpc.1 gpc-run.1 gpidump.1
INFO=		gpc gpcs gpcs-de gpcs-es gpcs-hr

# This port can be compiled with the GCC versions 2.8.1-2.95 and 3.2-3.4.3.
GCC_VERSION?=	3.4.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

post-extract:
	@${MV} ${WRKDIR}/p ${WRKSRC}/gcc

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^(lib(exec)?subdir =).*|\1 $$\(lib\2dir\)/gpc|; \
		 s|(\$$\(lib(exec)?dir\))/gcc|\1/gpc|; \
		 s|(-DDEFAULT_TARGET_(VERSION\|MACHINE)=\\").*(\\")|\1\3|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/gcc/Makefile.in
	@${REINPLACE_CMD} -e 's|read junk||' \
		${WRKSRC}/gcc/p/config-lang.in
	@${REINPLACE_CMD} -Ee 's|^(sed=)"`.*`"|\1sed|' \
		${WRKSRC}/gcc/p/script/extract-doc-demos
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -Ee 's|^(PASCAL_INSTALL_DOC=).*|\1|' \
		${WRKSRC}/gcc/p/Make-lang.in
.else
	@${REINPLACE_CMD} -Ee 's|^(P_DOC_DIR=).*|\1${DOCSDIR:S/${PREFIX}\///}|' \
		${WRKSRC}/gcc/p/Make-lang.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/gcc/libgcc_eh.a ${PREFIX}/lib/gpc
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>

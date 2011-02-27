# New ports collection makefile for:	gpc
# Date created:				28 Jun 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	gpc
PORTVERSION=	20060325
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.gnu-pascal.de/alpha/:gpc \
		${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${GCC_VER}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gpc \
		gcc-core-${GCC_VER}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Pascal compiler

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gsed:${PORTSDIR}/textproc/gsed \
		help2man:${PORTSDIR}/misc/help2man

DEPRECATED=	development has ceased; use lang/fpc instead
EXPIRATION_DATE=	2011-04-11

LICENSE=	GPLv2

USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-nls \
		--enable-languages=pascal \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--libexecdir=${PREFIX}/libexec/${PORTNAME}

WRKSRC=		${WRKDIR}/gcc-${GCC_VER}
INSTALL_WRKSRC=	${WRKSRC}/gcc
INSTALL_TARGET=	pascal.install-with-gcc

MAN1=		binobj.1 gpc.1 gpc-run.1 gpidump.1
INFO=		gpc gpcs gpcs-de gpcs-es gpcs-hr

PLIST_SUB=	GCC_VER="${GCC_VER}" GNU_HOST="${CONFIGURE_TARGET}"

# This port can be compiled with GCC versions 2.8.1 to 2.95 and 3.2 to 3.4.4.
GCC_VER?=	3.4.4

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
PLIST_SUB+=	CFM=""
.else
PLIST_SUB+=	CFM="@comment "
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Fails to deinstall on powerpc: leaves files behind
.endif

post-extract:
	@${MV} ${WRKDIR}/${DISTNAME}/p ${WRKSRC}/gcc

post-patch:
	@${REINPLACE_CMD} -e 's|read junk||' ${WRKSRC}/gcc/p/config-lang.in
	@${REINPLACE_CMD} -e 's|sed -|gsed -|' ${WRKSRC}/gcc/p/utils/mk-t-inc
	@${REINPLACE_CMD} -Ee \
		's|^(P_DOC_DIR=).*|\1${DOCSDIR:S/${PREFIX}\///}|' \
		${WRKSRC}/gcc/p/Make-lang.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|^\(PASCAL_INSTALL_DOC=\).*|\1|; \
	    s|$$(p_inst_docdir) $$(p_inst_demodir) $$(p_inst_docdemodir)||' \
	    ${WRKSRC}/gcc/p/Make-lang.in
.endif

post-install:
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	android-tools-fastboot
DISTVERSIONPREFIX=	platform-tools-
DISTVERSION?=	29.0.5
PORTREVISION?=	0
CATEGORIES=	devel sysutils
MASTER_SITES=	https://salsa.debian.org/android-tools-team/android-tools/raw/706e754/debian/:manpage
DISTFILES=	fastboot.1:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android Fastboot protocol CLI tool

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_TUPLE=	aosp-mirror:platform_system_core:${DISTVERSIONFULL} \
		jbeich:platform_external_avb:${DISTVERSIONFULL}:avb/avb \
		jbeich:platform_system_extras:${DISTVERSIONFULL}:extras/extras \
		jbeich:platform_system_tools_mkbootimg:${DISTVERSIONFULL}:mkbootimg/mkbootimg

CONFLICTS_INSTALL?=	${PORTNAME}-devel-*

USES=		compiler:c++17-lang pkgconfig ssl uidfix
BUILD_WRKSRC=	${WRKSRC}/fastboot
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE?=	${.CURDIR}/files/Makefile
MAKE_ENV=	BINDIR="${PREFIX}/bin" EXTRADIR="${FILESDIR}" \
		FILESDIR="${DOCSDIR}" \
		VERSION="${DISTVERSION}${DISTVERSIONSUFFIX}" \
		MANDIR="${PREFIX}/man/man"
PLIST_FILES=	bin/fastboot \
		man/man1/fastboot.1.gz
PORTDOCS=	*
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	BASH DOCS
OPTIONS_SUB=	yes

.if make(makesum) # for optional distfiles
.MAKEFLAGS:	WITH="${OPTIONS_DEFINE}"
.endif

BASH_GH_TUPLE=		mbrubeck:android-completion:c1b0656:bashcomp
BASH_PLIST_FILES=	etc/bash_completion.d/fastboot
BASH_VARS=		LICENSE+=MIT

DOCS_MAKE_ARGS_OFF=	FILES="" FILESDIR=""

post-extract:
	@${CP} ${_DISTDIR}/${DISTFILES:M*\:manpage:C/:.*//} \
		${BUILD_WRKSRC}

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${BASH_PLIST_FILES:H}
	${INSTALL_DATA} ${WRKSRC_bashcomp}/android \
		${STAGEDIR}${PREFIX}/${BASH_PLIST_FILES}

.include <bsd.port.mk>

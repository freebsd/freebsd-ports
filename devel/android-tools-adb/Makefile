# $FreeBSD$

PORTNAME=	android-tools-adb
DISTVERSIONPREFIX=	android-
DISTVERSION?=	5.1.1_r4
PORTREVISION?=	0
CATEGORIES=	devel
MASTER_SITES=	https://anonscm.debian.org/cgit/android-tools/android-tools.git/plain/debian/:bashcomp
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		bash_completion.d/adb?id=2b8cfec:bashcomp
EXTRACT_ONLY=	${DISTFILES:N*\:bashcomp:C/:.*//}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Android debug bridge command line tool

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	android
GH_PROJECT=	platform_system_core

CONFLICTS_INSTALL?=	${PORTNAME}-devel-*

USES+=		uidfix
.ifndef BUILD_WRKSRC
WRKSRC_SUBDIR=	adb
.endif
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	BINDIR="${PREFIX}/bin"

PLIST_FILES=	bin/adb \
		%%BASH%%etc/bash_completion.d/adb
PORTDOCS=	*.txt *.TXT

OPTIONS_DEFINE=	BASH DOCS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBASH}
LICENSE+=	MIT # debian/copyright
LICENSE_COMB=	multi
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M%%BASH%%*:C/%%.*%%//:H}
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES:M*\:bashcomp:C/:.*//} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M%%BASH%%*:C/%%.*%%//}
	(cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

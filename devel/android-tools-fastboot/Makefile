# $FreeBSD$

PORTNAME=	android-tools-fastboot
DISTVERSIONPREFIX=	android-
DISTVERSION=	5.1.1_r4
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://anonscm.debian.org/cgit/android-tools/android-tools.git/plain/debian/:bashcomp,manpage
DISTFILES=	bash_completion.d/fastboot?id=2b8cfec:bashcomp \
		fastboot.1?id=706e754:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:bashcomp:N*\:manpage:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android Fastboot protocol CLI tool

LICENSE=	APACHE20 BSD2CLAUSE PUBLIC_DOMAIN
LICENSE_COMB=	multi
LICENSE_NAME_PUBLIC_DOMAIN=	Public Domain
LICENSE_FILE_PUBLIC_DOMAIN=	${WRKSRC}/libselinux/NOTICE
LICENSE_PERMS_PUBLIC_DOMAIN=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_GITHUB=	yes
GH_ACCOUNT=	android jbeich:extras,libselinux
GH_PROJECT=	platform_system_core platform_system_extras:extras \
		platform_external_libselinux:libselinux

USES=		uidfix
BUILD_WRKSRC=	${WRKSRC}/fastboot
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	FILESDIR="${FILESDIR}" BINDIR="${PREFIX}/bin" \
		MANDIR="${PREFIX}/man/man" \
		LIBPCRE="${LOCALBASE}/lib/libpcre.a"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_FILES=	bin/fastboot \
		%%BASH%%etc/bash_completion.d/fastboot \
		man/man1/fastboot.1.gz
PORTDOCS=	fastboot_protocol.txt
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	BASH DOCS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBASH}
LICENSE+=	MIT # debian/copyright
.endif

post-extract:
	@${CP} ${_DISTDIR}/${DISTFILES:M*\:manpage:C/:.*//} \
		${BUILD_WRKSRC}/${DISTFILES:M*\:manpage:C/\?.*//}
# Adjust paths relative to core
	@(cd ${WRKSRC_extras} && ${COPYTREE_SHARE} . ${WRKSRC})
	@${MV} ${WRKSRC_libselinux} ${WRKSRC}/libselinux

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M%%BASH%%*:C/%%.*%%//:H}
	${INSTALL_DATA} ${_DISTDIR}/${DISTFILES:M*\:bashcomp:C/:.*//} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M%%BASH%%*:C/%%.*%%//}
	(cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

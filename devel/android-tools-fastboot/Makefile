# $FreeBSD$

PORTNAME=	android-tools-fastboot
DISTVERSIONPREFIX=	android-
DISTVERSION=	5.1.1_r4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://anonscm.debian.org/cgit/android-tools/android-tools.git/plain/debian/:manpage
DISTFILES=	fastboot.1?id=706e754:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android Fastboot protocol CLI tool

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	multi

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
		man/man1/fastboot.1.gz
PORTDOCS=	fastboot_protocol.txt

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${_DISTDIR}/${DISTFILES:M*\:manpage:C/:.*//} \
		${BUILD_WRKSRC}/${DISTFILES:M*\:manpage:C/\?.*//}
# Adjust paths relative to core
	@(cd ${WRKSRC_extras} && ${COPYTREE_SHARE} . ${WRKSRC})
	@${MV} ${WRKSRC_libselinux} ${WRKSRC}/libselinux

post-install:
	(cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

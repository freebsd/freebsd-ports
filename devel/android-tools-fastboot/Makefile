# $FreeBSD$

PORTNAME=	android-tools-fastboot
DISTVERSIONPREFIX=	android-
DISTVERSION=	4.2.2_r1.2
CATEGORIES=	devel
MASTER_SITES=	https://anonscm.debian.org/cgit/android-tools/android-tools.git/plain/debian/:manpage
DISTFILES=	fastboot.1?id=706e754:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android Fastboot protocol CLI tool

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	android jbeich:extras
GH_PROJECT=	platform_system_core platform_system_extras:extras

USES=		uidfix
BUILD_WRKSRC=	${WRKSRC}/fastboot
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	FILESDIR="${FILESDIR}" BINDIR="${PREFIX}/bin"
PLIST_FILES=	bin/fastboot \
		man/man1/fastboot.1.gz

post-extract:
# Adjust paths relative to core
	@(cd ${WRKSRC_extras} && ${COPYTREE_SHARE} . ${WRKSRC})

post-install:
	${INSTALL_MAN} ${_DISTDIR}/${DISTFILES:M*\:manpage:C/:.*//} \
		${STAGEDIR}${MAN1PREFIX}/man/man1/fastboot.1

.include <bsd.port.mk>

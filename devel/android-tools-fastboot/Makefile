# $FreeBSD$

PORTNAME=	android-tools-fastboot
DISTVERSIONPREFIX=	${GH_ACCOUNT}-
DISTVERSION=	4.0.4_r2.1
CATEGORIES=	devel
MASTER_SITES=	https://anonscm.debian.org/cgit/android-tools/android-tools.git/plain/debian/:manpage
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		fastboot.1?id=706e754:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Android Fastboot protocol CLI tool

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	android
GH_PROJECT=	platform_system_core

USES=		uidfix
WRKSRC_SUBDIR=	fastboot
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	FILESDIR="${FILESDIR}" BINDIR="${PREFIX}/bin"
PLIST_FILES=	bin/fastboot \
		man/man1/fastboot.1.gz

post-install:
	${INSTALL_MAN} ${_DISTDIR}/${DISTFILES:M*\:manpage:C/:.*//} \
		${STAGEDIR}${MAN1PREFIX}/man/man1/fastboot.1

.include <bsd.port.mk>

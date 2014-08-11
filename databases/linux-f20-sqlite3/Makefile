# Created by: Vassilis based on the respective port by bsam
# $FreeBSD:$

PORTNAME=	sqlite3
PORTVERSION=	1
CATEGORIES=	databases linux
MASTER_SITES=		http://archives.fedoraproject.org/pub/fedora/linux/releases/${LINUX_RPM_VERSION}/Everything/${LINUX_CPU_ARCH}/os/Packages/
PKGNAMEPREFIX=	linux-f20-
DISTFILES=	${BIN_DISTFILES}
EXTRACT_ONLY=		${DISTFILES} ${DISTFILES_DEPS}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM for SQL database engine (Linux Fedora 20)

BIN_DISTFILES=	\
			s/sqlite-3.8.1-2.fc${LINUX_RPM_VERSION}.${LINUX_RPM_ARCH}.rpm

# This probably should be in the USE_LINUX_APPS; waiting for modular support of linux_base
# of the user's choice in /usr/ports/Mk/bsd.linux-apps.mk
DISTFILES_DEPS=	\

CONFLICTS=	linux-f8-sqlite3-[0-9]* linux-f10-sqlite3-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
LINUX_CPU_ARCH=		i386
LINUX_RPM_ARCH=		i686
LINUX_RPM_VERSION=	20
USE_LINUX_PREFIX=	yes
USE_LINUX=			f20
NO_WRKSUBDIR=		yes
DISTINFO_FILE?=		${MASTERDIR}/distinfo.${LINUX_RPM_ARCH}

EXTRACT_CMD?=		${TAR}
EXTRACT_BEFORE_ARGS?=	-xPf
EXTRACT_AFTER_ARGS?=

do-build:

do-install:
	@cd ${WRKSRC} && ${FIND} * ! -path "stage*" -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/{}" \;
	@cd ${WRKSRC} && ${FIND} * ! -path "stage/*" ! -type d \
		| ${CPIO} -pm -R root:wheel ${STAGEDIR}${PREFIX}

USE_LDCONFIG=		yes

.include <bsd.port.mk>

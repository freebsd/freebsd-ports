# Created by: gordon@FreeBSD.org
# $FreeBSD$

PORTNAME=	p4
PORTVERSION=	${YEAR}.${MAJOR}.${MINOR}
PORTREVISION=	3
CATEGORIES=	devel
# Perforce stupidly rerolls their distfiles on a regular basis, updating the
# files' timestamps when they do, which changes the zip file's checksum.  Work
# around that by cacheing the distfile in LOCAL and using that version to make
# distinfo
MASTER_SITES=	LOCAL/asomers/perforce/p4 \
		https://swarm.workshop.perforce.com/projects/perforce_software-p4/archives/
DISTNAME=	${YEAR}-${MAJOR}
DISTFILES=	${ZIP_FILES}
DIST_SUBDIR=	perforce/p4

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Perforce client

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips64=	fails to install: /wrkdirs/usr/ports/devel/p4/work/2016-1/p4-bin/p4: No such file or directory
BROKEN_FreeBSD_11_powerpc64=	fails to build: /bin/sh: clang++: not found
BROKEN_FreeBSD_12_powerpc64=	fails to build: /bin/sh: clang++: not found

BUILD_DEPENDS=	${JAM}:devel/jam

# p4 links libssl and libcrypto statically, so specify :build
USES=		ssl:build

PLIST_FILES=	bin/p4

.include <bsd.port.pre.mk>

.include "Makefile.inc"

# Sadly, Jam always returns 1 even on success.  Ignore its return value and
# detect build errors during the install phase.
do-build:
	cd ${WRKSRC} && ${SETENV} C++="${CXX}" C++FLAGS="${CXXFLAGS}" \
		CCFLAGS="${CFLAGS}" \
		HDRS="${OPENSSLINC}" \
		LINKFLAGS="${LDFLAGS}" \
		OSVER=${OSVER} \
		SSL="yes" \
		SSLPREFIX=${OPENSSLLIB} \
		${JAM} -dx -j${MAKE_JOBS_NUMBER} || true

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/p4-bin/p4 ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>

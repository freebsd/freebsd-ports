PORTNAME=	p4
PORTVERSION=	${YEAR}.${MAJOR}.${MINOR}
PORTREVISION=	3
CATEGORIES=	devel
# Perforce changes their distfiles when they patch, which changes the
# zip file's checksum. This does not play well with FreeBSD's conventions.
# This version of the port 2016.1 is no longer available from Perforce's
# site. The new maintainer is backup hosting until the new port of 2022.2
# is ready.
MASTER_SITES=	LOCAL/asomers/perforce/p4 \
		https://hesiod.org/distfiles/
DISTNAME=	${YEAR}-${MAJOR}
DISTFILES=	${ZIP_FILES}
DIST_SUBDIR=	perforce/p4

MAINTAINER=	antonfb@hesiod.org
COMMENT=	Perforce client
WWW=		https://www.perforce.com/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_mips64=	fails to install: /wrkdirs/usr/ports/devel/p4/work/2016-1/p4-bin/p4: No such file or directory
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

PORTNAME=	p4api
PORTVERSION=	${YEAR}.${MAJOR}.${MINOR}
PORTREVISION=	1
CATEGORIES=	devel
# Perforce changes their distfiles when they patch, which changes the
# zip file's checksum. This does not play well with FreeBSD's conventions.
# Also, this port is for 2016.1 which no longer is available from Perforce's
# sites. The new maintainer will backup host until the new 2022.2 port is ready.
MASTER_SITES=	LOCAL/asomers/perforce/p4:zip \
		https://hesiod.org/distfiles/
DIST_SUBDIR=	perforce/p4
DISTNAME=	${YEAR}-${MAJOR}
DISTFILES=	${ZIP_FILES}:zip p4api.pdf:pdf
EXTRACT_ONLY=	${ZIP_FILES}

MAINTAINER=	antonfb@hesiod.org
COMMENT=	Perforce API (static libraries and header files)
WWW=		http://www.perforce.com/perforce/loadsupp.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_12_powerpc64=	fails to build: /bin/sh: clang++: not found

BUILD_DEPENDS=	${JAM}:devel/jam

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		zip

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>
.include "../p4/Makefile.inc"

# Sadly, Jam always returns 1 even on success.  Ignore its return value and
# detect build errors during the install phase.
do-build:
	cd ${WRKSRC} && ${SETENV} C++="${CXX}" C++FLAGS="${CXXFLAGS}" \
		CCFLAGS="${CFLAGS}" \
		LINKFLAGS="${LDFLAGS}" \
		OSVER=${OSVER} \
		API=1 \
		TYPE=pic \
		${JAM} -dx -j${MAKE_JOBS_NUMBER} || true

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/perforce
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/include/p4 && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/perforce
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/perforce
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/perforce

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/p4api.pdf ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/p4-bin/bin.pic/p4api-*/sample && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>

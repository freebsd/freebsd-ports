# $FreeBSD$

PORTNAME=	sofa
DISTVERSION=	20210125 # also called Release 17a
CATEGORIES=	astro devel
MASTER_SITES=	http://www.iausofa.org/${DISTVERSION:C/(....)(....)/\\1_\\2/}_C/
DISTNAME=	${PORTNAME}_c-${DISTVERSION}_a

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of algorithms and procedures used in fundamental astronomy

LICENSE=	SOFA
LICENSE_NAME=	SOFA Software License
LICENSE_FILE=	${WRKSRC}/../doc/copyr.lis
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

MAKEFILE=	makefile
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}/${DISTVERSION}_a/c/src
BINARY_ALIAS=	gcc=cc
MAKE_ARGS=	CFLAGF="-c ${CFLAGS} -fPIC" INSTALL_DIR=${STAGEDIR}${PREFIX}

PLIST_FILES=	include/sofa.h \
		include/sofam.h \
		lib/libsofa_c.so

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsofa_c.so

.include <bsd.port.mk>

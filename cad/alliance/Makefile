# Created by: hrs
# $FreeBSD$

PORTNAME=	alliance
DISTVERSION=	5.0-20120515
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	http://ftp.lyx.org/lip6/softs/alliance/distribution/5.0/ \
		http://ftp.jussieu.fr/lip6/softs/alliance/distribution/5.0/ \
		http://www-asim.lip6.fr/pub/alliance/distribution/5.0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete set of CAD tools and libraries for VLSI design

LICENSE=	Alliance
LICENSE_NAME=	Alliance VLSI Cad System License
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=		fails to link: collect2: error: ld returned 1 exit status

WRKSRC=		${WRKDIR}/alliance-5.0
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		bison gmake libtool motif

USE_GCC=	any
HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
ALLIANCE_TOP=	${PREFIX}/alliance
CONFIGURE_ENV+=	ALLIANCE_TOP=${ALLIANCE_TOP}
CONFIGURE_ARGS+=--mandir=${MANPREFIX}/man \
		--prefix=${ALLIANCE_TOP}

# The port does not build with C++11 or later (bug 219275).
USE_CXXSTD=	gnu++03

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e '/include <malloc.h>/d' \
		${WRKSRC}/xgra/src/XSB_parse.c

.include <bsd.port.mk>

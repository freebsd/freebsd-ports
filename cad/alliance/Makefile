# Created by: hrs
# $FreeBSD$

PORTNAME=	alliance
DISTVERSION=	5.1.1
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://asim.lip6.fr/pub/alliance/distribution/5.0/ \
		ftp://ftp.lyx.org/lip6/softs/alliance/distribution/5.0/ \
		ftp://ftp.jussieu.fr/lip6/softs/alliance/distribution/5.0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete set of CAD tools and libraries for VLSI design

LICENSE=	Alliance
LICENSE_NAME=	Alliance VLSI Cad System License
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=		fails to link: collect2: error: ld returned 1 exit status

BUILD_DEPENDS=	convert:graphics/ImageMagick7 \
		fig2dev:print/transfig

USES=		autoreconf:build compiler:c++0x gmake libtool motif \
		tar:bz2 xorg
USE_GCC=	any
USE_TEX=	dvipsk:build latex:build
USE_XORG=	ice sm x11 xext xt

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	ALLIANCE_TOP=${ALLIANCE_TOP}
CONFIGURE_ARGS+=--mandir=${MANPREFIX}/man \
		--prefix=${ALLIANCE_TOP}

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	fspclient-*

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/alliance/src

ALLIANCE_TOP=	${PREFIX}/alliance

post-patch:
	@${REINPLACE_CMD} -e '/include <malloc.h>/d' \
		${WRKSRC}/xgra/src/XSB_parse.c
	# These Makefiles contain hardcoded references to make(1). Replace them with
	# gmake(1) to avoid build failures of the documentation.
	@${REINPLACE_CMD} -e 's/; make/; gmake/' \
		${WRKSRC}/documentation/Makefile.am \
		${WRKSRC}/documentation/alliance-examples/Makefile \
		${WRKSRC}/documentation/tutorials/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ./autostuff

.include <bsd.port.mk>

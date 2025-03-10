PORTNAME=	alliance
DISTVERSION=	5.1.1
PORTREVISION=	6
CATEGORIES=	cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete set of CAD tools and libraries for VLSI design
WWW=		http://coriolis.lip6.fr/

LICENSE=	Alliance
LICENSE_NAME=	Alliance VLSI Cad System License
LICENSE_FILE=	${WRKSRC}/LICENCE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=	fails to link: collect2: error: ld returned 1 exit status

BUILD_DEPENDS=	fig2dev:print/fig2dev

USE_GITLAB=	yes
GL_SITE=	https://gitlab.lip6.fr
GL_ACCOUNT=	vlsi-eda
GL_TAGNAME=	ebece102e15c110fc79f1da50524c68fd9523f0c

USES=		autoreconf:build gmake libtool magick:build motif tar:bz2 tex xorg
USE_GCC=	yes
USE_TEX=	dvipsk:build latex:build
USE_XORG=	ice sm x11 xext xt

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	ALLIANCE_TOP=${ALLIANCE_TOP} YACC=${YACC}
CONFIGURE_ARGS+=--mandir=${PREFIX}/share/man \
		--prefix=${ALLIANCE_TOP} \
		--enable-alc-shared \
		--enable-shared
USE_LDCONFIG=	${ALLIANCE_TOP}/lib

MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip
CFLAGS+=	-fcommon \
		-fpermissive

CONFLICTS_INSTALL=	ocp publib

SUB_FILES=	pkg-message
WRKSRC_SUBDIR=	alliance/src

ALLIANCE_TOP=	${PREFIX}/alliance

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-configure:
	${REINPLACE_CMD} -e '/include <malloc.h>/d' \
		${WRKSRC}/xgra/src/XSB_parse.c
# Recursive make commands should always use the variable MAKE, not the
# explicit command name `make' (see the GNU make manual, section 5.7.1)
	${REINPLACE_CMD} -e 's/; make/; $$(MAKE)/' \
		${WRKSRC}/documentation/Makefile.am \
		${WRKSRC}/documentation/alliance-examples/Makefile \
		${WRKSRC}/documentation/tutorials/Makefile.am
	${RM} ${WRKSRC}/documentation/tutorials/Makefile.am.bak	\
		${WRKSRC}/documentation/alliance-examples/Makefile.bak
	cd ${WRKSRC} && ./autostuff

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${ALLIANCE_TOP}/tutorials
	(cd ${WRKSRC}/documentation/tutorials &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${ALLIANCE_TOP}/tutorials)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${ALLIANCE_TOP}/examples
	(cd ${WRKSRC}/documentation/alliance-examples &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${ALLIANCE_TOP}/examples)

.include <bsd.port.mk>

# New ports collection makefile for:	netpbm
# Date created:		?
# Whom:			jmz (original)
#
# $FreeBSD$
#

PORTNAME=	netpbm
PORTVERSION=	10.35.86
CATEGORIES=	graphics
MASTER_SITES=	SF/netpbm/super_stable/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A toolkit for conversion of images between different formats

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		jasper.4:${PORTSDIR}/graphics/jasper \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

MAKE_JOBS_UNSAFE=	yes

USE_PERL5=	yes
USE_GMAKE=	yes
CFLAGS+=	-DPNG_DEPSTRUCT= -Iutil
MAKE_ENV=	LN="${LN}" RANLIB="${RANLIB}"
MAKEFILE=	GNUmakefile
MAKEFILE2=	Makefile
INSTALL_TARGET=	install.bin install.lib install.data install-dev
USE_LDCONFIG=	yes

MAN1=		netpbm.1

.if defined(WITH_X11)
USE_XORG=	x11
MAKE_ENV+=	WITH_X11="${WITH_X11}"
PLIST_SUB+=	X11=''
.else
PLIST_SUB+=	X11='@comment '
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		 -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		 ${WRKSRC}/pm_config.in.h
	@${REINPLACE_CMD} -e 's|<shhopt.h>|<pm_shhopt.h>|g' ${WRKSRC}/lib/pm.h
	@${REINPLACE_CMD} -e 's| jpeg2000||g' \
		${WRKSRC}/converter/other/Makefile
	@${CP} ${PATCHDIR}/Makefile.config.FreeBSD ${WRKSRC}/Makefile.config
	@${LN} -sf ${WRKSRC}/lib/util/shhopt.h ${WRKSRC}/lib/util/pm_shhopt.h
	@${LN} -sf ${WRKSRC}/lib/util/nstring.h ${WRKSRC}/lib/util/pm_nstring.h
	cd ${WRKSRC} && buildtools/stamp-date > ${WRKSRC}/lib/compile.h

# This snippet is all it takes to make the port as of 10.35.80 MAKE_JOBS_SAFE:
pre-build:
	@(cd ${BUILD_WRKSRC}/lib/util; if ! ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE2} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}; then \
	if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
	    ${ECHO_MSG} "===> Compilation failed unexpectedly."; \
	    (${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
	    fi; \
	${FALSE}; \
	fi)

post-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/util/pm_c_util.h ${PREFIX}/include/
	@${ECHO_MSG} "===>  Installing man pages..."
	@${REINPLACE_CMD} -e 's|doc/USERDOC|${DOCSDIR}/USERDOC|g' \
		${WRKSRC}/doc/netpbm.1
	${INSTALL_MAN} ${WRKSRC}/doc/netpbm.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/USERDOC ${DOCSDIR}/
.endif

.include <bsd.port.mk>

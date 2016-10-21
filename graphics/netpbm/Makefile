# Created by: Jean-Marc Zucconi <jmz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netpbm
PORTVERSION=	10.35.98
CATEGORIES=	graphics
MASTER_SITES=	SF/netpbm/super_stable/${PORTVERSION} \
		LOCAL/dinoex/:man
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for conversion of images between different formats

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libjbig.so:graphics/jbigkit \
		libjasper.so:graphics/jasper \
		libxml2.so:textproc/libxml2

USES=		gmake jpeg perl5 shebangfix tar:tgz
SHEBANG_FILES=	editor/pnmflip editor/pnmquant editor/ppmfade \
		editor/ppmquant editor/ppmshadow generator/ppmrainbow
MAKEFILE=	GNUmakefile
MAKE_ENV=	LN="${LN}" RANLIB="${RANLIB}"
INSTALL_TARGET=	install.bin install.lib install.data install-dev
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-DPNG_DEPSTRUCT= -Iutil

OPTIONS_DEFINE=	X11 MANPAGES DOCS
OPTIONS_SUB=	yes

X11_USE=	xorg=x11
X11_MAKE_ENV=	WITH_X11=yes

MANPAGES_DISTFILES=	netpbm-manpages-2013-03-09${EXTRACT_SUFX}:man

post-extract-X11-off:
	@-${RM} ${WRKDIR}/doc/pamx.1 # only relevant for MANPAGES=on

post-patch:
	@${REINPLACE_CMD} -e 's|doc/USERDOC|${DOCSDIR}/USERDOC|g' \
		${WRKSRC}/doc/netpbm.1
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/pm_config.in.h
	@${REINPLACE_CMD} -e 's|^SCRIPTS =.*|SCRIPTS =|' ${WRKSRC}/GNUmakefile
	@${REINPLACE_CMD} -e 's|<shhopt.h>|<pm_shhopt.h>|g' ${WRKSRC}/lib/pm.h
	@${REINPLACE_CMD} -e 's| jpeg2000||g' \
		${WRKSRC}/converter/other/Makefile

do-configure:
	${CP} ${PATCHDIR}/Makefile.config.FreeBSD ${WRKSRC}/Makefile.config
	${LN} -sf ${WRKSRC}/lib/util/shhopt.h ${WRKSRC}/lib/util/pm_shhopt.h
	${LN} -sf ${WRKSRC}/lib/util/nstring.h ${WRKSRC}/lib/util/pm_nstring.h
	cd ${WRKSRC} && buildtools/stamp-date > ${WRKSRC}/lib/compile.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/util/pm_c_util.h ${STAGEDIR}${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/doc/netpbm.1 ${STAGEDIR}${PREFIX}/man/man1/

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKDIR}/doc/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKDIR}/doc/*.3 ${STAGEDIR}${PREFIX}/man/man3/
	${INSTALL_MAN} ${WRKDIR}/doc/*.5 ${STAGEDIR}${PREFIX}/man/man5/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/USERDOC ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

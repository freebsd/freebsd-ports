# New ports collection makefile for:	netpbm
# Date created:		?
# Whom:			jmz (original)
#
# $FreeBSD$
#

PORTNAME=	netpbm
PORTVERSION=	10.35.80
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/netpbm/super_stable/${PORTVERSION}
PKGNAMESUFFIX=	${NETPBM_SUFFIX}${PKGNAMESUFFIX2}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A toolkit for conversion of images between different formats

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		jasper.4:${PORTSDIR}/graphics/jasper \
		xml2.5:${PORTSDIR}/textproc/libxml2

MAKE_JOBS_UNSAFE=	yes

USE_PERL5=	yes
USE_GMAKE=	yes
USE_XORG=	x11
CFLAGS+=	-DPNG_DEPSTRUCT= -Iutil
MAKE_ENV=	LN="${LN}" RANLIB="${RANLIB}"
MAKEFILE=	GNUmakefile
INSTALL_TARGET=	install.bin install.lib install.data install-dev
USE_LDCONFIG=	yes

MAN1=		netpbm.1

pre-configure:
	@if [ -e ${DESTDIR}/${LOCALBASE}/include/pm.h ]; then \
		(${ECHO_MSG} "===> Cannot build with netpbm installed, please deinstall first"; exit 1) \
	fi
	if test -d "${DESTDIR}/${LOCALBASE}/include/pm.h
	end
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

post-install:
	@${ECHO_MSG} "===>  Installing man pages..."
	@${REINPLACE_CMD} -e 's|doc/USERDOC|${DOCSDIR}/USERDOC|g' \
		${WRKSRC}/doc/netpbm.1
	${INSTALL_MAN} ${WRKSRC}/doc/netpbm.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/USERDOC ${DOCSDIR}/
.endif

.include <bsd.port.mk>

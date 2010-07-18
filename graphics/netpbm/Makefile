# New ports collection makefile for:	netpbm
# Date created:		?
# Whom:			jmz (original)
#
# $FreeBSD$
#

PORTNAME=	netpbm
PORTVERSION=	${NETPBM_PORTVERSION}
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	# defined later
PKGNAMESUFFIX=	${NETPBM_SUFFIX}${PKGNAMESUFFIX2}
EXTRACT_SUFX=	.tgz
.if make(makesum) || defined(FETCH_ALL)
DISTFILES=	${PORTNAME}-${STABLE_PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${DEVEL_PORTVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A toolkit for conversion of images between different formats

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		jbig.1:${PORTSDIR}/graphics/jbigkit \
		jasper.4:${PORTSDIR}/graphics/jasper

MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	mgetty-1.*

USE_PERL5=	yes
USE_GMAKE=	yes
CFLAGS+=	-DPNG_DEPSTRUCT=
MAKE_ENV=	LN="${LN}" RANLIB="${RANLIB}"
MAKEFILE=	GNUmakefile
INSTALL_TARGET=	install.bin install.lib install.data install-dev
USE_LDCONFIG=	yes

MAN1=		netpbm.1

STABLE_PORTVERSION=	10.26.64
DEVEL_PORTVERSION=	10.35.76
.if defined(WITH_NETPBM_DEVEL)
MASTER_SITES=	SF/netpbm/super_stable/${DEVEL_PORTVERSION}
NETPBM_PORTVERSION=	${DEVEL_PORTVERSION}
PORTREVISION=	1
NETPBM_SUFFIX=	-devel
#CONFLICTS+=	netpbm-10.26.*
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
PATCHDIR?=	${MASTERDIR}/../netpbm-devel/files
USE_XORG=	x11
CFLAGS+=	-Iutil
PLIST_SUB+=	DEVEL=""
.else
MASTER_SITES=	SF/netpbm/super_stable/${PORTVERSION}
NETPBM_PORTVERSION=	${STABLE_PORTVERSION}
CONFLICTS+=	netpbm-devel-10.35.*
PORTSCOUT=	limit:^10\.26\.
PLIST_SUB+=	DEVEL="@comment "
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
.if defined(WITH_NETPBM_DEVEL)
	cd ${WRKSRC} && buildtools/stamp-date > ${WRKSRC}/lib/compile.h
.endif

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

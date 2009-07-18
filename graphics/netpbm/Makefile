# New ports collection makefile for:	netpbm
# Date created:		?
# Whom:			jmz (original)
#
# $FreeBSD$
#

PORTNAME=	netpbm
.if defined(WITH_NETPBM_DEVEL)
PORTVERSION=	${DEVEL_PORTVERSION}
.else
PORTVERSION=	10.26.63
.endif
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if defined(WITH_NETPBM_DEVEL)
PKGNAMESUFFIX=	-devel${PKGNAMESUFFIX2}
.endif
EXTRACT_SUFX=	.tgz
.if make(makesum) || defined(FETCH_ALL)
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${DEVEL_PORTVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A toolkit for conversion of images between different formats

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		jbig.1:${PORTSDIR}/graphics/jbigkit
#		jasper.4:${PORTSDIR}/graphics/jasper
.if defined(WITH_NETPBM_DEVEL)
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
.endif

MAKE_JOBS_UNSAFE=	yes
CONFLICTS=	mgetty-1.*
.if !defined(WITH_NETPBM_DEVEL)
PORTSCOUT=	limit:^10\.26\.
.endif

USE_PERL5=	yes
USE_GMAKE=	yes
MAKE_ENV=	LN="${LN}" RANLIB="${RANLIB}"
MAKEFILE=	GNUmakefile
INSTALL_TARGET=	install.bin install.lib install.data install-dev
USE_LDCONFIG=	yes

MAN1=		netpbm.1

DEVEL_PORTVERSION=	10.31
.if defined(WITH_NETPBM_DEVEL)
PATCHDIR?=	${MASTERDIR}/../netpbm-devel/files
CFLAGS+=	-Iutil
PLIST_SUB+=	DEVEL=""
.else
PLIST_SUB+=	DEVEL="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
# -O causes an ICE in converter/other/exif.c with gcc 3.3.3 on sparc64.
CFLAGS+=	-O0
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		 -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		 ${WRKSRC}/pm_config.in.h
	@${REINPLACE_CMD} -e 's|<shhopt.h>|<pm_shhopt.h>|g' ${WRKSRC}/lib/pm.h
	@${REINPLACE_CMD} -e 's| jpeg2000||g' \
		${WRKSRC}/converter/other/Makefile
	@${CP} ${FILESDIR}/Makefile.config.FreeBSD ${WRKSRC}/Makefile.config
	@${LN} -sf ${WRKSRC}/lib/util/shhopt.h ${WRKSRC}/lib/util/pm_shhopt.h
	@${LN} -sf ${WRKSRC}/lib/util/nstring.h ${WRKSRC}/lib/util/pm_nstring.h

post-install:
	@${ECHO_MSG} "===>  Installing man pages..."
	@${REINPLACE_CMD} -e 's|doc/USERDOC|${DOCSDIR}/USERDOC|g' \
		${WRKSRC}/doc/netpbm.1
	${INSTALL_MAN} ${WRKSRC}/doc/netpbm.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/USERDOC ${DOCSDIR}/
.endif

.if !defined(WITHOUT_PERL) && ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:    adun
# Date created:         4 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	adun
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	biology gnustep
MASTER_SITES=	http://download.gna.org/adun/
DISTNAME=	Adun${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Molecular Simulator for GNUstep

LIB_DEPENDS+=	gsl.10:${PORTSDIR}/math/gsl

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Adun
MAKE_ENV+=	AdunKernel_CURRENT_VERSION_NAME=0
DEFAULT_LIBVERSION2=	0.0
PLIST_SUB+=	LIBVERSION2=${DEFAULT_LIBVERSION2}
PLIST_SUB+=	MAJORLIBVERSION2=${DEFAULT_LIBVERSION2:C/([0-9]).*/\1/1}

post-patch:
	${REINPLACE_CMD} -e 's|include Defs/|-include Defs/|' \
		${WRKSRC}/MolTalk/GNUmakefile.preamble
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/Tools/GNUmakefile \
		${WRKSRC}/Tools/ResultsConverter/GNUmakefile \
		${WRKSRC}/MolTalk/GNUmakefile.preamble \
		${WRKSRC}/Kernel/GNUmakefile \
		${WRKSRC}/Kernel/AdunKernel/GNUmakefile \
		${WRKSRC}/UL/GNUmakefile \
		${WRKSRC}/UL/AdunServer/GNUmakefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		not enough math functions
.endif

.include <bsd.port.post.mk>

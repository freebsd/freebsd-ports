# New ports collection makefile for:    adun
# Date created:         4 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	adun
PORTVERSION=	0.6
CATEGORIES=	biology gnustep
MASTER_SITES=	http://download.gna.org/adun/
DISTNAME=	Adun${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Molecular Simulator for GNUstep

LIB_DEPENDS+=	gsl.9:${PORTSDIR}/math/gsl

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=		${WRKDIR}/Adun

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

.include <bsd.port.mk>

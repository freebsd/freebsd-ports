PORTNAME=	cenon
# Per r492056, 4.0.2 is the last version which actually works with GNUstep,
# the later ones use XCode >= 5 .xib files which GNUstep cannot parse.
PORTVERSION=	4.0.2
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.cenon.zone/download/source/
DISTNAME=	Cenon-${MAINVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector graphics tool for GNUstep
WWW=		https://www.cenon.info/dLinux_gb.html

USES=		gnustep tar:bzip2
USE_GNUSTEP=	gui base build
LLD_UNSAFE=	yes

WRKSRC=		${WRKDIR}/Cenon
MAINVERSION=	4.0.2
FULLVERSION=	4.0.0
CENON_LIB_DIR=	${GNUSTEP_SYSTEM_ROOT}/Library/Cenon

OPTIONS_DEFINE=	FULL_LIBRARY
FULL_LIBRARY_DESC=	Install complete Cenon Library

# Work around the fact that GNUstep doesn't define a constant for a higher
# version of AppKit that it supports.
OBJCFLAGS+=-DNSAppKitVersionNumber10_8=1200

.include <bsd.port.options.mk>

DISTFILES+=	CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX}

post-patch:
	@${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DOMAIN|#&|' \
		${WRKSRC}/GNUmakefile

pre-install:
	${MKDIR} ${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Library/
	${TAR} -xyvf ${_DISTDIR}/CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX} \
		-C ${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Library/ \
		--exclude COPYING --exclude '._*'

post-stage:
	${RM} ${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Library/README
	${RM} ${STAGEDIR}${GNUSTEP_SYSTEM_ROOT}/Library/._README

.include <bsd.port.mk>

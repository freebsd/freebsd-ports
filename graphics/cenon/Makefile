# New ports collection makefile for:	Cenon
# Date created:				16 Nov 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cenon
PORTVERSION=	3.71
CATEGORIES=	graphics
MASTER_SITES=	http://www.vhf-group.com/vhfInterservice/download/source/
DISTNAME=	Cenon-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A vector graphics tool for GNUstep

GNUSTEP_PREFIX?=	${LOCALBASE}/GNUstep
PREFIX=		${GNUSTEP_PREFIX}
NO_MTREE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/Cenon
MAKEFILE=	GNUmakefile

OPTIONS=	FULL_LIBRARY	"Install complete Cenon Library" off

.include <bsd.port.pre.mk>

.if defined(WITH_FULL_LIBRARY)
DISTFILES+=	CenonLibrary-${PORTVERSION}-1${EXTRACT_SUFX}
PLIST_SUB+=	FULL=""
.else
PLIST_SUB+=	FULL="@comment "
.endif

post-extract:
	@${REINPLACE_CMD} '/cp -R Library/d' ${WRKSRC}/GNUmakefile.postamble
	@${RM} -f ${WRKSRC}/Library/Cenon/Devices/gerber/gerber.doc
	@${FIND} ${WRKSRC}/Library -name COPYING -delete

post-install:
	-@${MKDIR} ${PREFIX}/Local/Library
.if defined(WITH_FULL_LIBRARY)
	${TAR} xyvf ${_DISTDIR}/CenonLibrary-${PORTVERSION}-1${EXTRACT_SUFX} \
		-C ${PREFIX}/Local/Library --exclude COPYING
	@${CHOWN} -R root:wheel ${PREFIX}/Local/Library/Cenon
	@${CHMOD} -R u=rwX,go=rX ${PREFIX}/Local/Library/Cenon
	@${CHMOD} 444 ${PREFIX}/Local/Library/Cenon/INSTALL
	${INSTALL_DATA} ${WRKSRC}/Library/Cenon/README ${PREFIX}/Local/Library/Cenon
.else
	${CP} -R ${WRKSRC}/Library/Cenon ${PREFIX}/Local/Library
.endif

.include <bsd.port.post.mk>

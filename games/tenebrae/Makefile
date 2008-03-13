# New ports collection makefile for: tenebrae
# Date created:		14 Mar 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	tenebrae
PORTVERSION=	1.04
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://tenebrae.sourceforge.net/downloads/
DISTFILES=	${PORTNAME}_src${EXTRACT_SUFX} \
		${PORTNAME}data${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake 1 source port with advanced graphics

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	yes

OPTIONS=	X86_ASM "Enable use of x86 assembly code" on

WRKSRC=		${WRKDIR}/${PORTNAME}_0
BUILD_WRKSRC=	${WRKSRC}/linux
MAKEFILE=	Makefile.i386linux
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X86_ASM)
MAKE_ENV+=	USE_ASM=1
.endif

pre-build:
	@cd ${BUILD_WRKSRC} && ${LN} -sf Makefile.i386linux Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/bin/${PORTNAME} \
		${PREFIX}/bin
	@${MKDIR} ${Q1DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/Pak0.pak ${Q1DIR}/${PORTNAME}
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TR} -d '\r' <${WRKDIR}/Tenebrae_Readme.txt \
		>${DOCSDIR}/Tenebrae_Readme.txt
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.post.mk>

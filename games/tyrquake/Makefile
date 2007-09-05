# New ports collection makefile for:	tyrquake
# Date created:				13 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	tyrquake
PORTVERSION=	0.57
CATEGORIES=	games
MASTER_SITES=	http://disenchant.net/files/engine/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Very conservative branch of the Quake source code

USE_GL=		yes
USE_GMAKE=	yes
MAKE_ENV=	QBASEDIR="${Q1DIR}"

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		X86_ASM "Enable x86 assembly code when possible" on

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=N
.endif

.if defined(WITHOUT_X86_ASM) || ${ARCH} != "i386"
MAKE_ENV+=	USE_X86_ASM=N
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-mtune/d' ${WRKSRC}/${MAKEFILE}

do-install:
.for file in tyr-quake tyr-glquake tyr-qwcl tyr-glqwcl tyr-qwsv
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>

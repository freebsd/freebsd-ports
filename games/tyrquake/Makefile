# Created by: alepulver
# $FreeBSD$

PORTNAME=	tyrquake
PORTVERSION=	0.59
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://disenchant.net/files/engine/

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Very conservative branch of the Quake source code

BROKEN=		Fails to build

USE_XORG=	x11 xxf86vm xdamage xfixes xau xext xdmcp
USE_GL=		yes
USE_GMAKE=	yes
MAKE_ENV=	QBASEDIR="${Q1DIR}" X11BASE=${LOCALBASE}

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFINE_i386=	ASM
ASM_DESC=	x86 assembly code when possible

OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS ASM

NO_STAGE=	yes
.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZED_CFLAGS=N
.endif

.if ! ${PORT_OPTIONS:MASM}
MAKE_ENV+=	USE_X86_ASM=N
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-mtune/d' ${WRKSRC}/${MAKEFILE}

do-install:
.for file in tyr-quake tyr-glquake tyr-qwcl tyr-glqwcl tyr-qwsv
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>

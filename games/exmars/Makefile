# New ports collection makefile for:	exmars
# Date created:				16 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	exmars
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/ankerl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Memory Array Redcode Simulator, just like exhaust and pMARS

REINPLACE_ARGS=	-i ''
ALL_TARGET=	${PORTNAME}

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilaton optimizations (>= 5.X)" on

do-install:
# Program.
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data.
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/warriors ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bench.sh ${DATADIR}

.include <bsd.port.pre.mk>

# Adjust optimization flags for all architectures.
.if ${ARCH} != "i386"
BADCFLAGS+=	-malign-double
.endif
.if ${ARCH} != "amd64" && ${ARCH} != "i386"
BADCFLAGS+=	-maccumulate-outgoing-args \
		-minline-all-stringops \
		-mno-align-stringops
.endif
.if ${ARCH} == "alpha"
BADCFLAGS+=	-ffast-math \
		-fprefetch-loop-arrays
.endif

post-patch:
# Fix bench.sh.
	@${REINPLACE_CMD} -e 's|pmars|pmars-server| ; \
		s|\./exmars|exmars|' \
		${WRKSRC}/bench.sh

# Fix Makefile.
	@${REINPLACE_CMD} -e 's|\($${OPT}\)|${CFLAGS} \1|' ${WRKSRC}/${MAKEFILE}

# Enable/disable compilation optimizations.
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|$${OPT}||' ${WRKSRC}/${MAKEFILE}
.endif

# Adjust optimization flags for all architectures.
.for f in ${BADCFLAGS}
	@${REINPLACE_CMD} -e 's|${f}||g' ${WRKSRC}/${MAKEFILE}
.endfor

.include <bsd.port.post.mk>

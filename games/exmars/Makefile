# New ports collection makefile for:	exmars
# Date created:				16 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	exmars
PORTVERSION=	0.01
CATEGORIES=	games
MASTER_SITES=	http://martinus.geekisp.com/files/

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Memory Array Redcode Simulator, just like exhaust and pMARS

USE_REINPLACE=	yes

ALL_TARGET=	${PORTNAME}

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" off

do-install:
# Program
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/warriors ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/bench.sh ${DATADIR}

.include <bsd.port.pre.mk>

post-patch:
# Fix bench.sh
	@${REINPLACE_CMD} -e 's|pmars|pmars-server| ; \
			s|\./exmars|exmars|' \
				${WRKSRC}/bench.sh

# Enable/disable compilation optimizations
	@${REINPLACE_CMD} -e 's|\($${OPT}\)|${CFLAGS} \1|' ${WRKSRC}/${MAKEFILE}
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|$${OPT}||' ${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	fmars
# Date created:				16 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	fmars
PORTVERSION=	0.0.207
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://users.v-lo.krakow.pl/~michal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Memory Array Redcode Simulator

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile

USE_BZIP2=	yes
USE_GMAKE=	yes

ALL_TARGET=	x${PORTNAME}

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

.include <bsd.port.pre.mk>

post-patch:
# Fix Makefile.
	@${REINPLACE_CMD} -e 's|\($$(OPT)\)|${CFLAGS} \1| ; \
		s|gcc|${CC}|g' \
		${WRKSRC}/${MAKEFILE}

# Enable/disable compilation optimizations.
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|$$(OPT)||' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
# Program.
	${INSTALL_PROGRAM} ${WRKSRC}/x${PORTNAME} ${PREFIX}/bin/${PORTNAME}

# Data.
	${MKDIR} ${DATADIR}
.for d in rc rc-test
	${CP} -R ${WRKSRC}/${d} ${DATADIR}
.endfor

# Documentation (optional).
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
# Fix permissions.
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644
	@${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755

.include <bsd.port.post.mk>

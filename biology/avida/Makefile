# New ports collection makefile for:	avida
# Date created:		17 April 2002
# Whom:			Jeremy <karlj000@unbc.ca>
#
# $FreeBSD$
#

PORTNAME=	avida
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://dllab.caltech.edu/avida/versions/

MAINTAINER=	karlj000@unbc.ca
COMMENT=	Avida is an auto-adaptive genetic system designed for ALife research

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.[[:alnum:]]+$//}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-viewer --enable-standard-prefix --prefix=${PREFIX} --datadir=${PREFIX}/share/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

post-patch:
	# Change source/defs.hh prefix and port name.
	@ ${MV} ${WRKSRC}/source/defs.hh ${WRKSRC}/source/defs.hh.presed
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${WRKSRC}/source/defs.hh.presed \
	| ${SED} -e 's#%%PORTNAME%%#${PORTNAME}#g' \
	> ${WRKSRC}/source/defs.hh

	# Change source/support/genesis prefix and port name.
	@ ${MV} ${WRKSRC}/source/support/genesis ${WRKSRC}/source/support/genesis.presed
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${WRKSRC}/source/support/genesis.presed \
	| ${SED} -e 's#%%PORTNAME%%#${PORTNAME}#g' \
	> ${WRKSRC}/source/support/genesis

	# Change source/support/genesis.heads prefix and port name.
	@ ${MV} ${WRKSRC}/source/support/genesis.heads ${WRKSRC}/source/support/genesis.heads.presed
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' ${WRKSRC}/source/support/genesis.heads.presed \
	| ${SED} -e 's#%%PORTNAME%%#${PORTNAME}#g' \
	> ${WRKSRC}/source/support/genesis.heads

.include <bsd.port.post.mk>

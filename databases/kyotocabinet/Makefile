# New ports collection makefile for:	kyotocabinet
# Date created:		22 April 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kyotocabinet
PORTVERSION=	0.9.15
CATEGORIES=	databases
MASTER_SITES=	http://1978th.net/kyotocabinet/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A straightforward implementation of DBM

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	PCDIR="${PREFIX}/libdata/pkgconfig"

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

MAN1=		kccachetest.1 \
		kchashmgr.1 \
		kchashtest.1 \
		kclangctest.1 \
		kcpolymgr.1 \
		kcpolytest.1 \
		kcprototest.1 \
		kctreemgr.1 \
		kctreetest.1 \
		kcutilcodec.1 \
		kcutiltest.1

check: build
	cd ${WRKSRC}; ${MAKE} check

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/kyotocabinet.idl ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "COPYING ChangeLog THANKS doc" ${DOCSDIR}/
.endif

.include <bsd.port.mk>

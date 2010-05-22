# New ports collection makefile for:	kyotocabinet
# Date created:		22 April 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kyotocabinet
PORTVERSION=	1.0.0
CATEGORIES=	databases
MASTER_SITES=	http://1978th.net/kyotocabinet/

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A straightforward implementation of DBM

MAKE_JOBS_SAFE=	yes

USE_GCC=	4.2+
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	PCDIR="${PREFIX}/libdata/pkgconfig"

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && !defined(CPUTYPE)
CONFIGURE_TARGET=	i586-portbld-freebsd${OSREL}
CPUTYPE=	i586
PKGMESSAGE=	${FILESDIR}/pkg-message.${ARCH}
# _CPUCFLAGS will somehow show up twice in CFLAGS but who cares..
.include <bsd.cpu.mk>
.endif

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
.if exists(${PKGMESSAGE})
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>

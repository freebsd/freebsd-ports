# New ports collection makefile for:	kyotocabinet
# Date created:		22 April 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	kyotocabinet
PORTVERSION=	1.2.70
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A straightforward implementation of DBM

LICENSE=	GPLv3

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

MAN1=		kccachetest.1 \
		kcdirmgr.1 \
		kcdirtest.1 \
		kcforestmgr.1 \
		kcforesttest.1 \
		kcgrasstest.1 \
		kchashmgr.1 \
		kchashtest.1 \
		kclangctest.1 \
		kcpolymgr.1 \
		kcpolytest.1 \
		kcprototest.1 \
		kcstashtest.1 \
		kctreemgr.1 \
		kctreetest.1 \
		kcutilmgr.1 \
		kcutiltest.1

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/DOCDIR/d' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${FIND} ${DOCSDIR}/ -type d -exec ${CHMOD} 755 '{}' \;
	${FIND} ${DOCSDIR}/ -type f -exec ${CHMOD} 444 '{}' \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/
.endif
.if exists(${PKGMESSAGE})
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>

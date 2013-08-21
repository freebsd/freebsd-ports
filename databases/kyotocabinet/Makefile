# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	kyotocabinet
PORTVERSION=	1.2.76
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Straightforward implementation of DBM

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKE_ARGS=	PCDIR="${PREFIX}/libdata/pkgconfig"
USE_GCC=	4.2+
USE_LDCONFIG=	yes
USES=		gmake

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && !defined(CPUTYPE)
CONFIGURE_TARGET=	i586-portbld-freebsd${OSREL}
CPUTYPE=	i586
PKGMESSAGE=	${FILESDIR}/pkg-message.${ARCH}
# _CPUCFLAGS will somehow show up twice in CFLAGS but who cares..
.include <bsd.cpu.mk>
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not link on powerpc
.endif

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/DOCDIR/d' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${FIND} ${DOCSDIR}/ -type d -exec ${CHMOD} 755 '{}' \;
	${FIND} ${DOCSDIR}/ -type f -exec ${CHMOD} 444 '{}' \;
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/
.endif
.if exists(${PKGMESSAGE})
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	uudx
# Date created:		2 June 1996
# Whom:			ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	uudx
PORTVERSION=	2.99
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/dos/util/bin/conv/
DISTNAME=	uudx_299
EXTRACT_SUFX=	.lzh

MAINTAINER=	rewsirow@ff.iij4u.or.jp
COMMENT=	Extractor from uuencoded files

EXTRACT_DEPENDS=lha:${PORTSDIR}/archivers/lha
BUILD_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xfqw=${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty

NO_WRKSUBDIR=	yes
MANLANG=	ja
MAN1=		uudx.1
PLIST_FILES=	bin/uudx

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

pre-patch:
	@${ECHO_MSG} "===>  Installing custom Makefile for ${DISTNAME}"
	@(${CP} ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.post.mk>

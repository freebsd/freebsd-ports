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
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//}
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

pre-patch:
	@${ECHO_MSG} "===>  Installing custom Makefile for ${DISTNAME}"
	@(${CP} ${FILESDIR}/Makefile ${WRKSRC})

post-patch:
	@${REINPLACE_CMD} -e '/sprintf()/d' ${WRKSRC}/uudx.c

.include <bsd.port.mk>

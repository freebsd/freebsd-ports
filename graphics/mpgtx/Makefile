# ex:ts=8
# New ports collection makefile for:	mpgtx
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mpgtx
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	shared
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_MAN="${INSTALL_MAN}"

MAN1=	mpgtx.1 tagmp3.1
MLINKS=	mpgtx.1 mpgdemux.1 \
	mpgtx.1 mpgjoin.1 \
	mpgtx.1 mpgsplit.1 \
	mpgtx.1 mpgcat.1 \
	mpgtx.1 mpginfo.1

post-install:
	@(cd ${PREFIX}/bin ; \
	${LN} -sf mpgtx mpgdemux ; \
	${LN} -sf mpgtx mpgjoin ; \
	${LN} -sf mpgtx mpgsplit ; \
	${LN} -sf mpgtx mpgcat ; \
	${LN} -sf mpgtx mpginfo ; \
	${LN} -sf mpgtx tagmp3)

.include <bsd.port.mk>

# New ports collection makefile for:	noweb
# Date created:		29 July 1995
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	noweb
PORTVERSION=	2.10a
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tg

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	icont:${PORTSDIR}/lang/icon
RUN_DEPENDS=	iconx:${PORTSDIR}/lang/icon

WRKSRC=		${WRKDIR}/src
MAN1=		cpif.1 htmltoc.1 nodefs.1 noindex.1 noroff.1 noroots.1 \
		notangle.1 noweb.1 nuweb2noweb.1 sl2h.1
MAN7=		nowebfilters.7 nowebstyle.7
MLINKS=		notangle.1 noweave.1	notangle.1 nountangle.1

post-build:
	@(cd ${WRKSRC} && ${SH} ${WRKSRC}/awkname awk)

.include <bsd.port.mk>

# New ports collection makefile for:	noweb
# Date created:		29 July 1995
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	noweb
PORTVERSION=	2.9a
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.virginia.edu/pub/nr/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	icont:${PORTSDIR}/lang/icon
RUN_DEPENDS=	iconx:${PORTSDIR}/lang/icon

WRKSRC=		${WRKDIR}/src
MAN1=		cpif.1 nodefs.1 noroots.1 noweb.1 noindex.1 \
		noroff.1 nuweb2noweb.1 notangle.1 sl2h.1 htmltoc.1
MAN7=		nowebstyle.7 nowebfilters.7
MLINKS=		notangle.1 noweave.1	notangle.1 nountangle.1

post-build:
	@(cd ${WRKSRC} && ${WRKSRC}/awkname awk)

.include <bsd.port.mk>

# New ports collection makefile for:	gnome2-office
# Date created:				07 January 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome2-office
PORTVERSION=	2.4.2
CATEGORIES=	editors gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 office applications

RUN_DEPENDS=	gnumeric:${PORTSDIR}/math/gnumeric2 \
		planner:${PORTSDIR}/deskutils/planner \
		dia:${PORTSDIR}/graphics/dia \
		glabels:${PORTSDIR}/deskutils/glabels \
		evolution:${PORTSDIR}/mail/evolution \
		mergeant:${PORTSDIR}/databases/mergeant

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "alpha" || ${OSVERSION} >= 500000
RUN_DEPENDS+=	AbiWord-2.0:${PORTSDIR}/editors/AbiWord2
.endif

do-install:	# empty

.include <bsd.port.post.mk>

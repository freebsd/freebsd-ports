# New ports collection makefile for:    CSSC
# Date created:         31 Mar 1999
# Whom:                 Oliver Fromme
#
# $FreeBSD$
#

PORTNAME=	cssc
PORTVERSION=	0.15a.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	CSSC-0.15alpha.pl0

MAINTAINER=	olli@fromme.com
COMMENT=	A workalike for the source code control system SCCS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-binary
MAN1=		sccs.1
INFO=		cssc

WRKSRC=		${WRKDIR}/CSSC-0.15alpha.pl0

.include <bsd.port.mk>

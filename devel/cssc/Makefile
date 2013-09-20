# Created by: Oliver Fromme
# $FreeBSD$

PORTNAME=	cssc
PORTVERSION=	0.15a.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/0.15alpha.pl0
DISTNAME=	CSSC-0.15alpha.pl0

MAINTAINER=	olli@fromme.com
COMMENT=	A workalike for the source code control system SCCS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-binary
MAN1=		sccs.1
INFO=		cssc

WRKSRC=		${WRKDIR}/CSSC-0.15alpha.pl0

NO_STAGE=	yes
.include <bsd.port.mk>

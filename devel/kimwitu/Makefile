# ex:ts=8
# New ports collection makefile for:	kimwitu
# Date created:			Apr 23, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kimwitu
PORTVERSION=	4.6.1
CATEGORIES=	devel
MASTER_SITES=	http://www.sourcefiles.org/Programming/Compilers/Object-Oriented/
DISTNAME=	kc-distr.V${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for processing trees (i.e. terms)

WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=
MAKE_JOBS_UNSAFE=	yes

MAN1=		kc.1
PLIST_FILES=	bin/kc

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Gen/kc ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/../man/kc.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

# New ports collection makefile for:	tuxnes
# Date created:		13 Feb 2000
# Whom:			Jeroen Ruigrok van der Werven <asmodai@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tuxnes
PORTVERSION=	0.73
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://tmmm.simplenet.com/tuxnes/packages/
MASTER_SITE_SUBDIR=	asmodai

MAINTAINER=	asmodai@freebsd.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	YES
USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES

ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>

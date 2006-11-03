# New ports collection makefile for:	kasm
# Date created:				28 Aug 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kasm
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	k-asm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A System RPL/Machine Language assembler for the HP48/HP49 calculators

DEPRECATED=	Buggy and unmaintained, use devel/hptools instead
EXPIRATION_DATE=2007-01-01

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes
PORTDOCS=	*

OPTIONS=	HP48 "set the default output model to hp48 instead of hp49" off

.include <bsd.port.pre.mk>

.if defined(WITH_HP48)
CONFIGURE_ARGS+=	--with-default=hp48
.endif

post-patch:
	@${RM} -f ${WRKSRC}/src/getopt.h

.include <bsd.port.post.mk>

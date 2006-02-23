# New ports collection makefile for:	libpperl
# Date created:			December 14, 2005
# Whom:				Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpperl
PORTVERSION=	20051214
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~kbyanc/ \
		http://www.posi.net/software/libpperl/

MAINTAINER=	kbyanc@FreeBSD.org
COMMENT=	A library easing embedding perl interpreters into C programs

WRKSRC=		${WRKDIR}/${PORTNAME}

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		this library only supports perl 5.8.0 or above
.endif

.include <bsd.port.post.mk>

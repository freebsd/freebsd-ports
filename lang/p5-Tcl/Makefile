# New ports collection makefile for:	p5-Tcl
# Date created:				June 15th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tcl
PORTVERSION=	b2
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tcl
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Tcl.3

.include <bsd.port.mk>

# New ports collection makefile for:	p5-GDS2
# Date created:				Sun, Apr 29 2007
# Whom:					Hiroki Sato <hrs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GDS2
PORTVERSION=	2.09.a
CATEGORIES=	cad perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GDS2
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.a$,a,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GDS2 - GDS2 stream module

PERL_MODBUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S,.a$,,}
PLIST_FILES=	${SITE_PERL_REL}/GDS2.pm \
		${PROGRAMS:S,^,bin/,}

MAN3=		GDS2.3

PROGRAMS=	gdsdump2gds modgds2 gdslayers testgds2 \
		gdspath4topath0 testgdt
# XXX: gdsdump disabled for the moment

post-install:
	${INSTALL_SCRIPT} ${PROGRAMS:S,^,${WRKSRC}/Examples/,} ${PREFIX}/bin

.include <bsd.port.mk>

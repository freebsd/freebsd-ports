# Created by: Hiroki Sato <hrs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	GDS2
PORTVERSION=	3.00
CATEGORIES=	cad perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.a$,a,}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GDS2 - GDS2 stream module

USES=		perl5
USE_PERL5=	modbuild
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

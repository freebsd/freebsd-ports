# $FreeBSD$

PORTNAME=	GDS2
PORTVERSION=	3.28
CATEGORIES=	cad perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GDS2 stream module

RUN_DEPENDS=	p5-Tk>=804.027:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-Tk-WaitBox>0:${PORTSDIR}/x11-toolkits/p5-Tk-WaitBox

USES=		perl5 shebangfix
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S,.a$,,}
SHEBANG_FILES=	Examples/*
PLIST_FILES=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/GDS2/.packlist \
		%%SITE_PERL%%/GDS2.pm \
		${PROGRAMS:S,^,bin/,} \
		%%PERL5_MAN3%%/GDS2.3.gz
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/GDS2

PROGRAMS=	gds2dump gdsdump2gds modgds2 gdslayers testgds2 \
		gdspath4topath0 testgdt

post-install:
	${INSTALL_SCRIPT} ${PROGRAMS:S,^,${WRKSRC}/Examples/,} \
	    ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

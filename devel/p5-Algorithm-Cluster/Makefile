# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Algorithm-Cluster
PORTVERSION=	1.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MDEHOON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to C clustering library

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BROKEN_FreeBSD_13_i386=	ld: error: can't create dynamic relocation R_386_32 against local symbol in readonly segment; recompile object files with -fPIC or pass '-Wl,-z,notext' to allow text relocations in the output #'

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Algorithm/Cluster/Cluster.so

.include <bsd.port.mk>

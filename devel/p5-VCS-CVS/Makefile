# Created by: Anatoliy Dmytriyev <tolid@plab.ku.dk>
# $FreeBSD$

PORTNAME=	VCS-CVS
PORTVERSION=	2.06
CATEGORIES=	devel perl5
MASTER_SITES=	http://savage.net.au/Perl-modules/ \
		http://tolid.eu.org/VCSCVS/
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	tolid@plab.ku.dk
COMMENT=	Perl module that provides a simple interface to CVS

BUILD_DEPENDS=	p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	modbuild
MAN3=		VCS::CVS.3

NO_STAGE=	yes
.include <bsd.port.mk>

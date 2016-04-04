# Created by: Jase Thew <freebsd@beardz.net>
# $FreeBSD$

PORTNAME=	Reflex
PORTVERSION=	0.099
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RCAPUTO
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	Class library for flexible, reactive programs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE>=1.294:devel/p5-POE \
		p5-Moose>=2.0203:devel/p5-Moose \
		p5-MooseX-Role-Parameterized>=0.23:devel/p5-MooseX-Role-Parameterized
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure

OPTIONS_DEFINE=	DOCS EXAMPLES

SHEBANG_FILES=	eg/*.pl

post-extract:
	@${RM} ${WRKSRC}/bench.pl
	@${REINPLACE_CMD} -e '/^bench.pl$$/d' ${WRKSRC}/MANIFEST

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}"
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/proto/ ${STAGEDIR}${EXAMPLESDIR}/ttl/
	${INSTALL_SCRIPT} ${WRKSRC}/eg/*.pl ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/eg/*.pm ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/eg/proto/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/proto/
	cd ${WRKSRC}/eg/ttl/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/ttl/
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}"

.include <bsd.port.mk>

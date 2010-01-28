# New ports collection makefile for:    Devel-Size-Report
# Date created:                         Wed 04 Nov 2009
# Whom:                                 Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	Devel-Size-Report
PORTVERSION=	0.13
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Extension to generate a size report for all elements in a structure

BUILD_DEPENDS=	p5-Array-RefElem>=1.00:${PORTSDIR}/misc/p5-Array-RefElem \
		p5-Devel-Size>=0.69:${PORTSDIR}/devel/p5-Devel-Size
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Devel::Size::Report.3

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>

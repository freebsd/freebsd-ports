# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	DNS-Zone
PORTVERSION=	0.85
PORTREVISION=	0
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DNS::Zone is set of perl modules for name service zone files

USES=		perl5
USE_PERL5=	configure patch

post-patch:
	${FIND} ${WRKSRC} -name '*.pm' -o -name '*.t' -o -name '*.PL' | \
	${XARGS} ${PERL} -pi -e '$$_="" if /^use 5/;' \
			     -e '$$_="" if /(use|no) warnings/;'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Penguin
PORTVERSION=	3.00
PORTREVISION=	1
CATEGORIES=	devel security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Framework for passing digitally signed perl5 code between machines

RUN_DEPENDS=	pgp:security/pgp

USES=		perl5
USE_PERL5=	configure

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/perl5/site_perl/Penguin/bin ${STAGEDIR}${PREFIX}/lib/perl5/site_perl/Penguin/misc ${STAGEDIR}${PREFIX}/lib/perl5/site_perl/Penguin/doc
	${INSTALL_DATA} ${WRKSRC}/bin/.pen ${STAGEDIR}${PREFIX}/lib/perl5/site_perl/Penguin/bin
.for i in makeapplet pclient penguind runapplet
	${INSTALL} -m ${BINMODE} ${WRKSRC}/bin/${i} ${STAGEDIR}${PREFIX}/lib/perl5/site_perl/Penguin/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/misc/* ${STAGEDIR}${PREFIX}/lib/perl5/site_perl/Penguin/misc
.for i in FAQ INSTALL MODULE_NOTES README SECURITY TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/lib/perl5/site_perl/Penguin/doc
.endfor

.include <bsd.port.mk>

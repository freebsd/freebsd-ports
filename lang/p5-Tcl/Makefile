# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tcl
PORTVERSION=	1.02
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VKON
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tcl extension module for Perl5

CONFIGURE_ARGS=	--nousestubs --tclsh ${TCLSH}
USES=		perl5
USE_PERL5=	configure
USE_TCL=	84+

post-extract:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 0755 \{} \;
	@${FIND} ${WRKSRC} -type f -exec ${CHMOD} 0644 \{} \;

.include <bsd.port.mk>

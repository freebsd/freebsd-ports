PORTNAME=	libxml-enno
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	devel textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ENNO
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Group of Perl modules for XML parsing

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-libwww>=0:www/p5-libwww \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-libxml>=0:textproc/p5-libxml \
		p5-Parse-Yapp>=0:devel/p5-Parse-Yapp
RUN_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-libwww>=0:www/p5-libwww \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-libxml>=0:textproc/p5-libxml \
		p5-Parse-Yapp>=0:devel/p5-Parse-Yapp

CONFLICTS=	p5-XML-DOM p5-XML-Filter-DetectWS \
		p5-XML-Filter-Reindent p5-XML-Filter-SAXT \
		p5-XML-RegExp p5-XML-XQL

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

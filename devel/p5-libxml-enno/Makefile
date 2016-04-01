# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

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

CONFLICTS=	p5-XML-DOM-[0-9]* p5-XML-Filter-DetectWS-[0-9]* \
		p5-XML-Filter-Reindent-[0-9]* p5-XML-Filter-SAXT-[0-9]* \
		p5-XML-RegExp-[0-9]* p5-XML-XQL-[0-9]*

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

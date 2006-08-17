# New ports collection makefile for:	converters/p5-WAP-wbxml
# Date created:				1 Aug 2006
# Whom:					Timur I. Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=	WAP-wbxml
PORTVERSION=	1.10
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WAP/PERRAD
PKGNAMEPREFIX=	p5-

MAINTAINER=	bat@cpan.org
COMMENT=	Binarization of XML file

BUILD_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${SITE_PERL}/I18N/Charset.pm:${PORTSDIR}/misc/p5-I18N-Charset \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		wbxmlc.pl.1
MAN3=		WAP::wbxml.3

post-patch:
.for file in syncml.wbrules.xml wap.wbrules.xml wbxmlc.pl wbxml.pm wv.wbrules.xml
		@${PERL} -pi -e 's#\r$$##g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>

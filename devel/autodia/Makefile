# ex:ts=8
# New ports collection makefile for:	autodia
# Date created:			Oct 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	autodia
PORTVERSION=	1.7
PORTREVISION=	0
CATEGORIES=	devel perl5
MASTER_SITES=	http://droogs.org/autodia/download/
DISTNAME=	Autodia-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic Dia XML - from Source Code and Data

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Inline/Java.pm:${PORTSDIR}/devel/p5-Inline-Java \
		${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz \
		${SITE_PERL}/VCG.pm:${PORTSDIR}/graphics/p5-VCG \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Autodia.3 autodia.3 autodia_java.3 \
	Autodia::Diagram.3 \
	Autodia::Diagram::Class.3 \
	Autodia::Diagram::Component.3 \
	Autodia::Handler.3 \
	Autodia::Handler::Cpp.3 \
	Autodia::Handler::DBI.3 \
	Autodia::Handler::PHP.3 \
	Autodia::Handler::Perl.3 \
	Autodia::Handler::SQL.3 \
	Autodia::Handler::Torque.3 \
	Autodia::Handler::dia.3

DOCS=	CHANGES COPYING CREDITS DEVELOP FAQ INSTALL README TODO

pre-install:
	@${RM} -f ${WRKSRC}/blib/man3/*.3pm

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

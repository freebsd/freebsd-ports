# New ports collection makefile for:	p5-Config-Auto
# Date created:				August 29 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Config-Auto
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Config
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	Magical config file parser

BUILD_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Config::Auto.3

test:
	cd ${WRKSRC} ; make test

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec

post-patch:
	@${PERL} -pi -e 's/^our (\$$\w+)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if (/5.006/);' \
		 ${WRKSRC}/Auto.pm
.endif

.include <bsd.port.post.mk>

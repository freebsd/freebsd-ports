# New ports collection makefile for:	devel/p5-Perl-Version
# Date created:				10 April 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Perl-Version
PORTVERSION=	1.009
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse and manipulate Perl version strings

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils

PERL_CONFIGURE=	yes

OPTIONS=	PERLREVERSION "Install perl-reversion script" on

.include <bsd.port.pre.mk>

.ifdef(WITH_PERLREVERSION)
.if ${PERL_LEVEL} < 5.008007
BUILD_DEPENDS+=	p5-Pod-Parser>=1.3:${PORTSDIR}/textproc/p5-Pod-Parser
RUN_DEPENDS+=	p5-Pod-Parser>=1.3:${PORTSDIR}/textproc/p5-Pod-Parser
.endif
BUILD_DEPENDS+=	p5-File-Slurp>=9999.12:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS+=	p5-File-Slurp>=9999.12:${PORTSDIR}/devel/p5-File-Slurp
MAN1=		perl-reversion.1
PROMPT=		Y
PLIST_SUB=	PERLREVERSION=
.else
PROMPT=		N
PLIST_SUB=	PERLREVERSION="@comment "
.endif

post-patch:
	@${PERL} -pi -e 's/my \$$yn/my \$$yn="${PROMPT}"; #/;' ${WRKSRC}/Makefile.PL

MAN3=	Perl::Version.3

.include <bsd.port.post.mk>

# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBIx-Class-EncodedColumn
PORTVERSION=	0.00012
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatically encode columns

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DBIx-Class>=0.06002:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-Sub-Name>=0.04:${PORTSDIR}/devel/p5-Sub-Name \
		p5-SQL-Translator>=0.09.003:${PORTSDIR}/databases/p5-SQL-Translator
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Dir-Self>=0:${PORTSDIR}/devel/p5-Dir-Self

USES=		perl5
USE_PERL5=	configure extract

post-extract:
	@${PERL} -i -ne 'print unless m,^build_requires, || m,^feature, .. m,;,' ${WRKSRC}/Makefile.PL

OPTIONS_DEFINE=	SHA BLOWFISH OPENPGP
OPTIONS_DEFAULT=	SHA BLOWFISH OPENPGP
SHA_DESC=	Digest::SHA Support
BLOWFISH_DESC=	Blowfish Support
OPENPGP_DESC=	Crypt::OpenPGP (gpg) Support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBLOWFISH}
RUN_DEPENDS+=	p5-Crypt-Eksblowfish>=0:${PORTSDIR}/security/p5-Crypt-Eksblowfish
.endif

.if ${PORT_OPTIONS:MOPENPGP}
RUN_DEPENDS+=	p5-Crypt-OpenPGP>=0:${PORTSDIR}/security/p5-Crypt-OpenPGP \
		p5-Crypt-CAST5_PP>=0:${PORTSDIR}/security/p5-Crypt-CAST5_PP
.endif

.include <bsd.port.post.mk>

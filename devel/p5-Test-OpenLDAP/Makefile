# $FreeBSD$

PORTNAME=	Test-OpenLDAP
PORTVERSION=	0.05
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to creates temp instance of slapd to run tests against

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Data-UUID>0:devel/p5-Data-UUID \
	p5-perl-ldap>0:net/p5-perl-ldap \
	${LOCALBASE}/libexec/slapd:net/openldap${OPENLDAP_VER}-server \
	p5-Net>0:net/p5-Net
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_OPENLDAP=	yes

CONFIGURE_ENV=	PATH=${PATH}:${PREFIX}/libexec

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		-e 's|/usr/lib/openldap|${LOCALBASE}/libexec|' \
		${WRKSRC}/lib/Test/OpenLDAP.pm
	${RM} ${WRKSRC}/lib/Test/OpenLDAP.pm.bak \
		${WRKSRC}/lib/Test/OpenLDAP.pm.orig

.include <bsd.port.mk>

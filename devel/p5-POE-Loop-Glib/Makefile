# Created by: Jase Thew <freebsd@beardz.net>
# $FreeBSD$

PORTNAME=	POE-Loop-Glib
PORTVERSION=	0.038
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:APOCAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	A bridge that supports Glib event loop from POE

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-POE>=1.288:${PORTSDIR}/devel/p5-POE \
		p5-Glib2>=1.222:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
USES=		perl5
USE_PERL5=	configure

MAN3=		POE::Loop::Glib.3

NO_STAGE=	yes
post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

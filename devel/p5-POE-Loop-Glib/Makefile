# New ports collection makefile for:	POE-Loop-Glib
# Date created:	   Jul 30 2010
# Whom:		   Jase Thew <freebsd@beardz.net>
#
# $FreeBSD$
#

PORTNAME=	POE-Loop-Glib
PORTVERSION=	0.038
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:APOCAL
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd@beardz.net
COMMENT=	A bridge that supports Glib event loop from POE

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-POE>=1.288:${PORTSDIR}/devel/p5-POE \
		p5-Glib2>=1.222:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
PERL_CONFIGURE=	yes

MAN3=		POE::Loop::Glib.3

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

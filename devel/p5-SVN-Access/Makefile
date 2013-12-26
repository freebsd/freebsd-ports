# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	SVN-Access
PORTVERSION=	0.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension to manipulate SVN Access files

BUILD_DEPENDS=	p5-subversion>=0:${PORTSDIR}/devel/p5-subversion \
		p5-Tie-IxHash>=1.21:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS=	p5-subversion>=0:${PORTSDIR}/devel/p5-subversion \
		p5-Tie-IxHash>=1.21:${PORTSDIR}/devel/p5-Tie-IxHash

USES=		perl5
USE_PERL5=	configure

MAN3=		SVN::Access.3 \
		SVN::Access::Group.3 \
		SVN::Access::Resource.3

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
STRIP=
PORTEXAMPLES=	svnaclmgr.pl

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${INSTALL_PROGRAM} ${PORTEXAMPLES} \
		${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

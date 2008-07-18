# New ports collection makefile for:	p5-SVN-Access
# Date created:		2008-02-11
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SVN-Access
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Perl extension to manipulate SVN Access files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Base.pm:${PORTSDIR}/devel/p5-subversion \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/SVN/Base.pm:${PORTSDIR}/devel/p5-subversion \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML

PERL_CONFIGURE=	yes

MAN3=		SVN::Access.3 \
		SVN::Access::Group.3 \
		SVN::Access::Resource.3

post-install:
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -name \*.pl -type f -print0 | \
		${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${EXAMPLESDIR} -name \*.pl -type f -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}

.include <bsd.port.mk>

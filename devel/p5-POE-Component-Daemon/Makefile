# New ports collection makefile for:	devel/p5-POE-Component-Daemon
# Date created:				24 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Daemon
PORTVERSION=	0.1008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Handles all the housework for a daemon in POE

BUILD_DEPENDS=	${SITE_PERL}/POE/API/Peek.pm:${PORTSDIR}/devel/p5-POE-API-Peek \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Daemon.3

PORTDOCS=	*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@for i in ${WRKSRC}/*forking; do \
		${PERL} -pi -e '$$_ = undef if m{use FindBin}o;' \
			-e 's{.FindBin::Dir(.+)$$}{/tmp$$1\nwarn "Logging to \$$logfile\\n";}o' $${i}; \
		${INSTALL_SCRIPT} $${i} ${EXAMPLESDIR}; \
	done

.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${WRKSRC}/*.png; do \
		${INSTALL_DATA} $${i} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>

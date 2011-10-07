# New ports collection makefile for:	devel/p5-POE-Component-Daemon
# Date created:				24 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Daemon
PORTVERSION=	0.1300
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Handles all the housework for a daemon in POE

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-POE>=1:${PORTSDIR}/devel/p5-POE

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Daemon.3

PORTDOCS=	*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@for i in ${WRKSRC}/eg/*forking; do \
		${PERL} -pi -e '$$_ = undef if m{use FindBin}o;' \
			-e 's{.FindBin::Dir(.+)$$}{/tmp$$1\nwarn "Logging to \$$logfile\\n";}o' $${i}; \
		${INSTALL_SCRIPT} $${i} ${EXAMPLESDIR}; \
	done

.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${WRKSRC}/eg/*.png ${WRKSRC}/eg/*.dot; do \
		${INSTALL_DATA} $${i} ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>

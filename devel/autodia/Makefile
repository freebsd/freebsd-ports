# ex:ts=8
# New ports collection makefile for:	autodia
# Date created:			Oct 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	autodia
PORTVERSION=	1.2
PORTREVISION=	0
CATEGORIES=	devel perl5
MASTER_SITES=	http://droogs.org/autodia/download/
DISTNAME=	AutoDia-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PERL_SITELIBDIR}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${PERL_SITELIBDIR}/Inline.pm:${PORTSDIR}/devel/p5-Inline \
		${PERL_SITELIBDIR}/Inline/Java.pm:${PORTSDIR}/devel/p5-Inline-Java
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_SITELIBDIR=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
USE_BZIP2=	yes
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/Autodia

MAN1=	autodia.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Autodia.3 Autodia::Diagram.3 Autodia::Diagram::Class.3 \
	Autodia::Diagram::Component.3 Autodia::Handler.3 \
	Autodia::Handler::Cpp.3 Autodia::Handler::PHP.3 \
	Autodia::Handler::Perl.3

DOCS=	CHANGES COPYING CREDITS DEVELOP FAQ INSTALL README

pre-install:
	@${RM} -f ${WRKSRC}/blib/man3/*.3pm

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	ruby-rbprof
# Date created:		08 April 2002
# Whom:			Sean Chittenden <sean@chittenden.org>
#
# $FreeBSD$
#

PORTNAME=	rbprof
PORTVERSION=	0.2.1
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aspectr
DISTNAME=	aspectr-0-3-5
DIST_SUBDIR=	ruby

MAINTAINER=	sean@chittenden.org
COMMENT=	A flexible Ruby profiler

#RUN_DEPENDS=	${RUBY_SITELIBDIR}/runit/error.rb:${PORTSDIR}/devel/ruby-unit \
#		${RUBY_SITELIBDIR}/aspectr.rb:${PORTSDIR}/devel/ruby-aspectr

USE_RUBY=	yes

NO_BUILD=       yes

do-install:
	${MKDIR} ${PORTDOCS}${RUBY_DOCDIR}/rbprof
	${INSTALL_DATA} ${WRKSRC}/README ${PORTDOCS}${RUBY_DOCDIR}/rbprof/
	${INSTALL_DATA} ${WRKSRC}/TODO ${PORTDOCS}${RUBY_DOCDIR}/rbprof/
	${RUBY} -p -i -e 'gsub(/\r\n/, "\n")' ${WRKSRC}/aspects/profiler/lib/rbprof.rb
	${RUBY} -p -i -e 'gsub(/\r\n/, "\n")' ${WRKSRC}/aspects/profiler/lib/trap_method_definitions.rb
	${INSTALL_DATA} ${WRKSRC}/aspects/profiler/lib/rbprof.rb ${RUBY_SITELIBDIR}/
	${MKDIR} ${RUBY_SITELIBDIR}/rbprof
	${INSTALL_DATA} ${WRKSRC}/aspects/profiler/lib/trap_method_definitions.rb ${RUBY_SITELIBDIR}/rbprof/

.include <bsd.port.mk>

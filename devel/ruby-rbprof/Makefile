# Created by: Sean Chittenden <sean@chittenden.org>
# $FreeBSD$

PORTNAME=	rbprof
PORTVERSION=	0.2.1
CATEGORIES=	devel ruby
MASTER_SITES=	SF/aspectr/aspectr/0.3.5
DISTNAME=	aspectr-0-3-5
DIST_SUBDIR=	ruby

MAINTAINER=	sean@chittenden.org
COMMENT=	Flexible Ruby profiler

OPTIONS_DEFINE=	DOCS

#RUN_DEPENDS=	${RUBY_SITELIBDIR}/runit/error.rb:devel/ruby-unit \
#		${RUBY_SITELIBDIR}/aspectr.rb:devel/ruby-aspectr

USES=		dos2unix

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/rbprof
	@${MKDIR} ${STAGEDIR}${PORTDOCS}${RUBY_DOCDIR}/rbprof
	${INSTALL_DATA} ${WRKSRC}/README \
		${WRKSRC}/TODO ${STAGEDIR}${PORTDOCS}${RUBY_DOCDIR}/rbprof/
	${RUBY} -p -i -e 'gsub(/\r\n/, "\n")' ${WRKSRC}/aspects/profiler/lib/rbprof.rb
	${RUBY} -p -i -e 'gsub(/\r\n/, "\n")' ${WRKSRC}/aspects/profiler/lib/trap_method_definitions.rb
	${INSTALL_DATA} ${WRKSRC}/aspects/profiler/lib/rbprof.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/aspects/profiler/lib/trap_method_definitions.rb ${STAGEDIR}${RUBY_SITELIBDIR}/rbprof/

.include <bsd.port.mk>

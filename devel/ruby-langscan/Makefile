# New ports collection makefile for:	ruby-langscan
# Date created:		2011-08-10
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	langscan
PORTVERSION=	1.2
CATEGORIES=	devel ruby
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	gonzui/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	${RUBY_PKGNAMEPREFIX:S|${RUBY_SUFFIX}-||}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A program analyzer for source code search engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	flex>=2.5.31:${PORTSDIR}/textproc/flex \
		p5-PPI>=0:${PORTSDIR}/textproc/p5-PPI

GNU_CONFIGURE=	yes
USE_RUBY=	yes
USE_PERL5_RUN=	yes
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes

PORTDOCS=	ChangeLog NEWS README
DOCSDIR=	${RUBY_MODDOCDIR}

post-install:
	${CHMOD} ${BINMODE} ${RUBY_SITEARCHLIBDIR}/${PORTNAME}/ocaml/camlexer
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

x-generate-plist:
	${ECHO} %%RUBY_SITELIBDIR%%/langscan.rb > pkg-plist.new
	${FIND} ${RUBY_SITEARCHLIBDIR}/${PORTNAME} -type f | ${SORT} | ${SED} -e 's,${RUBY_SITEARCHLIBDIR},%%RUBY_SITEARCHLIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type f | ${SORT} | ${SED} -e 's,${RUBY_SITELIBDIR},%%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITELIBDIR}/${PORTNAME} -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITELIBDIR},@dirrm %%RUBY_SITELIBDIR%%,' >> pkg-plist.new
	${FIND} ${RUBY_SITEARCHLIBDIR}/${PORTNAME} -type d -depth | ${SORT} -r | ${SED} -e 's,${RUBY_SITEARCHLIBDIR},@dirrm %%RUBY_SITEARCHLIBDIR%%,' >> pkg-plist.new

.include <bsd.port.mk>

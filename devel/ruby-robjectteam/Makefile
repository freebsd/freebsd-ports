# New ports collection makefile for:	RubyObjectTeams
# Date created:		9 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	robjectteam
PORTVERSION=	1.0
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Enables the ObjectTeams paradigm to the Ruby language

USE_RUBY=	yes

NO_BUILD=	yes

PLIST_FILES=	%%RUBY_SITELIBDIR%%/objectteam.rb
DOCSDIR=	${RUBY_MODDOCDIR}

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

# XXX: exists untill it will be committed to bsd.port.mk
COPYTREE_SHARE=	${SH} -c '(${FIND} -d $$0 $$2 | ${CPIO} -dumpl $$1 >/dev/null \
		2>&1) && \
		${CHOWN} -R ${SHAREOWN}:${SHAREGRP} $$1 && \
		${FIND} $$1/ -type d -exec ${CHMOD} 755 {} \; && \
		${FIND} $$1/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;' --

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}

	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_MODDOCDIR}/
	@(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR})
	@${FIND} ${RUBY_MODEXAMPLESDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_MODEXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

post-install:
	@${FIND} ${RUBY_SITELIBDIR}/objectteam ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${RUBY_SITELIBDIR}/objectteam -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>

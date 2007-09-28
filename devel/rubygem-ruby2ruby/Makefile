# New ports collection makefile for:	rubygem-ruby2ruby
# Date created:		2007-09-28
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	ruby2ruby
PORTVERSION=	1.1.7
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	seattlerb

MAINTAINER=	tota@rtfm.jp
COMMENT=	A pure ruby code generator easily from ParseTree's Sexps

BUILD_DEPENDS=	rubygem-parsetree>=0.0:${PORTSDIR}/devel/rubygem-parsetree
RUN_DEPENDS=	${BUILD_DEPENDS}

x-generate-plist:
	${ECHO} %%GEM_CACHE%% > pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},%%GEM_DOC_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},%%GEM_LIB_DIR%%,' >> pkg-plist.new
	${ECHO} %%GEM_SPEC%% >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm %%GEM_LIB_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm %%GEM_DOC_DIR%%,' >> pkg-plist.new

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>

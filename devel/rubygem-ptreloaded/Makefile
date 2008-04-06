# New ports collection makefile for:	rubygem-ptreloaded
# Date created:		2007-09-28
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	ptreloaded
PORTVERSION=	0.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ParseTreeReloaded-${PORTVERSION}

MAINTAINER=	tota@rtfm.jp
COMMENT=	A reimplementation of ParseTree using RubyInlineAcceleration

BUILD_DEPENDS=	rubygem-rubyinlineaccel>=0.0.1:${PORTSDIR}/devel/rubygem-rubyinlineaccel
RUN_DEPENDS=	${BUILD_DEPENDS}

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes

x-generate-plist:
	${ECHO} %%GEM_CACHE%% > pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},%%GEM_DOC_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},%%GEM_LIB_DIR%%,' >> pkg-plist.new
	${ECHO} %%GEM_SPEC%% >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm %%GEM_LIB_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm %%GEM_DOC_DIR%%,' >> pkg-plist.new

.include <bsd.port.mk>

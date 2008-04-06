# Ports collection makefile for:	gem-rake
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	rake
PORTVERSION=	0.8.1
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jw@innerewut.de
COMMENT=	Ruby Make

USE_RUBY=	yes
USE_RUBYGEMS=	yes

MANCOMPRESSED=	yes
MAN1=		rake.1

x-generate-plist:
	${ECHO} bin/rake > pkg-plist.new
	${ECHO} %%GEM_CACHE%% >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},%%GEM_DOC_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},%%GEM_LIB_DIR%%,' >> pkg-plist.new
	${ECHO} %%GEM_SPEC%% >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm %%GEM_LIB_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm %%GEM_DOC_DIR%%,' >> pkg-plist.new

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
IGNORE=	already included in ruby distribution
.endif

post-install:
	${MV} ${PREFIX}/${GEM_LIB_DIR}/doc/rake.1.gz \
		${PREFIX}/man/man1
	${CHMOD} ${MANMODE} ${PREFIX}/man/man1/rake.1.gz
	${CHOWN} ${MANOWN}:${MANGRP} ${PREFIX}/man/man1/rake.1.gz

.include <bsd.port.post.mk>

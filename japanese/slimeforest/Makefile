# New ports collection makefile for:	sfa
# Date created:				21 August 2004
# Whom:					nivit@email.it
#
# $FreeBSD$
#

PORTNAME=	slimeforest
PORTVERSION=	0.53
CATEGORIES=	japanese games linux
MASTER_SITES=	http://lrnj.com/
DISTNAME=	sfa
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@users.sourceforge.net
COMMENT=	A NES RPG game for learning KANA and KANJI (linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL_image-1.2.so.0:${PORTSDIR}/graphics/linux-sdl_image

NO_BUILD=	yes
USE_LINUX=	yes

WRKSRC=		${WRKDIR}/slimeforest
FIND_DIRS=	-type d \! -empty
FIND_EXEC=	\! -type d -and -perm -a+x \! -name "*.bak" \! -name "*.orig"
FIND_DATA=	\! -type d -and \! -perm -a+x -and \! -name "*.txt"
LINK_OPTS=	-s

REPLACE_FILES=	runfs runwin

post-patch:
	@for FILE in ${REPLACE_FILES}; do \
		${SED} -i .bak\
		-e "/\`dirname.*\`/s//${DATADIR:S/\//\\\//g}/g" \
		${WRKSRC}/$${FILE}; \
	done;

do-install:
# programs and data
	@cd ${WRKSRC}; \
	DIRS=$$(${FIND} . ${FIND_DIRS}); \
	for DIR in $${DIRS}; do \
		${MKDIR} ${DATADIR}/$${DIR}; \
	done; \
	FILES=$$(${FIND} . ${FIND_EXEC} ); \
	for FILE in $${FILES}; do \
		${INSTALL_SCRIPT} $${FILE} ${DATADIR}/$${FILE}; \
	done; \
	FILES=$$(${FIND} . ${FIND_DATA}); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${DATADIR}/$${FILE}; \
	done;
# links to executables
	${LN} ${LINK_OPTS} ${DATADIR}/runfs ${PREFIX}/bin/slimeforest-fs
	${LN} ${LINK_OPTS} ${DATADIR}/runwin ${PREFIX}/bin/slimeforest-win

.include <bsd.port.mk>

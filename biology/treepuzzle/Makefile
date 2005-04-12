# Ports collection makefile for:	treepuzzle
# Date created:				26 August 2002
# Whom:					lentferj
#
# $FreeBSD$
#

PORTNAME=	treepuzzle
PORTVERSION=	5.2
CATEGORIES=	biology
MASTER_SITES=	http://www.tree-puzzle.de/
DISTNAME=	tree-puzzle-${PORTVERSION}

MAINTAINER=	jan.lentfer@web.de
COMMENT=	Maximum likelihood phylogeny reconstruction using quartets

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
PLIST_FILES=	bin/puzzle

pre-configure:
	@${ECHO_MSG} "---------------------------------------------"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to install the parallel version of tree-puzzle, you need to install"
	@${ECHO_MSG} "from the ports and have to have a MPI-Implementation on your system."
	@${ECHO_MSG} "The tree-puzzle configure script will then automatically build the normal and"
	@${ECHO_MSG} "parallel version (puzzle & ppuzzle)."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "---------------------------------------------"

.include <bsd.port.mk>

# New ports collection makefile for:	devel/easygit
# Date created:				11 March 2009
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	easygit
PORTVERSION=	0.98
CATEGORIES=	devel
MASTER_SITES=	http://www.gnome.org/~newren/eg/download/${PORTVERSION}/
DISTNAME=	eg
EXTRACT_SUFX=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Easy wrapper for git

RUN_DEPENDS=	git:${PORTSDIR}/devel/git

DIST_SUBDIR=	eg/${PORTVERSION}_${PORTREVISION}
USES=		perl5
USE_PERL5=	run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/eg bin/easygit

do-install:
	${INSTALL_SCRIPT} ${_DISTDIR}/eg ${PREFIX}/bin/
	${LN} -s ${PREFIX}/bin/eg ${PREFIX}/bin/easygit

.include <bsd.port.mk>

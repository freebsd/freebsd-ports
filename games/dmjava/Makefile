# New ports collection makefile for:	dmjava
# Date Created:		1 Sep 2002
# Whom:			Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	dmjava
PORTVERSION=	1.037
CATEGORIES=	games
MASTER_SITES=	http://www.toppoint.de/~hscholz/dmjava/ \
		http://phobos.raisdorf.net/~olivleh1/src/ \
		http://www.owlserver.de:2080/ftp/pub/echo/gfd/gfd.app.game/ \
		ftp://ftp.owlserver.de/pub/echo/gfd/gfd.app.game/ \
		http://keok.mine.nu/gfd/appgame/ \
		http://www.dmjump.net/patches/
DISTFILES=	DMJ.ZIP ${MY_PATCHFILES}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	DMJ.ZIP

MAINTAINER=	lehmann@ans-netz.de

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

MY_PATCHFILES=	PATCH1.ZIP PATCH2.ZIP PATCH3.ZIP PATCH35.ZIP PATCH36.ZIP PATCH37.ZIP

USE_ZIP=	yes
USE_JAVA=	1.3+

SCRIPTS_ENV=	BASEDIR="${WRKSRC}"

pre-patch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/dmj-rename.sh

post-patch:
.for i in ${MY_PATCHFILES}
	@${EXTRACT_CMD} -oq ${DISTDIR}/${DIST_SUBDIR}/$i ${EXTRACT_AFTER_ARGS}
.endfor

do-build:	# empty

do-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}
	@${CP} -r ${WRKSRC}/* ${PREFIX}/${PORTNAME}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To start dmjava, type 'cd ${PREFIX}/${PORTNAME} && javavm dmnew'"
	@${ECHO_MSG} ""
.include <bsd.port.mk>

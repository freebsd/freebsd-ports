# New ports collection makefile for:	insub
# Date created:			27 Dec 2003
# Whom:				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	insub
PORTVERSION=	6.5
PORTREVISION?=	0
CATEGORIES?=	irc
MASTER_SITES=	http://gruntle.org/projects/irssi/gay/

MAINTAINER?=	alfred@FreeBSD.org
COMMENT?=	Some scripts for expressing how you really feel on irc

WITH_PERL=	YES

BUILD_DEPENDS+=	irsii:${PORTSDIR}/irc/irssi
RUN_DEPENDS+=	figlet:${PORTSDIR}/misc/figlet
BUILD_DEPENDS+=	cowsay:${PORTSDIR}/games/cowsay

.include <bsd.port.pre.mk>

COWS!=sed 's@^@cows/@' < ${FILESDIR}/cows
SCRIPT=gay-${PORTVERSION}.pl
INSTSCRIPT=gay.pl
DISTFILES= ${SCRIPT} ${COWS}
DIST_SUBDIR?= insub
NO_BUILD=YES
EXTRACT_CMD=echo
DISTCOWS=${COWS:S@^@${DISTDIR}/${DIST_SUBDIR}/@}

pre-extract:
	[ -d "${WRKDIR}" ] || mkdir ${WRKDIR}

# $PREFIX/share/irssi

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${SCRIPT} \
		${LOCALBASE}/share/irssi/scripts/${INSTSCRIPT}
	for i in ${DISTCOWS} ; do \
		${INSTALL_DATA} $$i ${LOCALBASE}/share/cows ;	\
	done

.include <bsd.port.post.mk>

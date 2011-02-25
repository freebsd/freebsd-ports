# New ports collection makefile for:	inform7
# Date created:				23 September 2010
# Whom:					Andy Kosela <akosela@andykosela.com>
#
# $FreeBSD$
#

PORTNAME=	inform7
PORTVERSION=	6G60
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://ftp.ifarchive.org/if-archive/infocom/compilers/inform7/source/:1 \
		http://ifarchive.heanet.ie/if-archive/infocom/compilers/inform7/source/:1 \
		http://ftp.ifarchive.org/if-archive/infocom/compilers/inform7/executables/:2 \
		http://ifarchive.heanet.ie/if-archive/infocom/compilers/inform7/executables/:2
DISTFILES=	inform6.zip:1 \
		I7_6G60_FreeBSD.zip:2

MAINTAINER=	akosela@andykosela.com
COMMENT=	Inform 7 programming language (CLI edition)

RUN_DEPENDS=	frotz:${PORTSDIR}/games/frotz

ONLY_FOR_ARCHS=	i386 amd64

USE_ZIP=	yes
SUB_FILES=	i7.sh

MAN6=		i7.6

.include <bsd.port.pre.mk>

do-build:
	@cd ${WRKDIR} && ${CC} ${CFLAGS} -o inform6 *.c

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/i7.sh ${PREFIX}/bin/i7
	@${INSTALL_PROGRAM} ${WRKDIR}/inform6 ${PREFIX}/bin/inform6

	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKDIR}/Extensions ${DATADIR}

	@${INSTALL_MAN} ${FILESDIR}/i7.6 ${MAN6PREFIX}/man/man6

.if ${ARCH} == "i386"
	@${INSTALL_PROGRAM} ${WRKDIR}/ni.i386 ${PREFIX}/bin/ni
.else
	@${INSTALL_PROGRAM} ${WRKDIR}/ni.amd64 ${PREFIX}/bin/ni
.endif

.include <bsd.port.post.mk>

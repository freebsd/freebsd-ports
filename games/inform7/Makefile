# Created by: Andy Kosela <akosela@andykosela.com>
# $FreeBSD$

PORTNAME=	inform7
PORTVERSION=	6L02
CATEGORIES=	games
MASTER_SITES=	http://ftp.ifarchive.org/if-archive/infocom/compilers/inform7/executables/ \
		http://ifarchive.heanet.ie/if-archive/infocom/compilers/inform7/executables/
DISTFILES=	I7_6L02_FreeBSD.zip

MAINTAINER=	akosela@andykosela.com
COMMENT=	Inform 7 programming language (CLI edition)

RUN_DEPENDS=	frotz:${PORTSDIR}/games/frotz

ONLY_FOR_ARCHS=	i386 amd64

USES=		zip
SUB_FILES=	i7.sh

.include <bsd.port.pre.mk>

do-build:

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/i7.sh ${STAGEDIR}${PREFIX}/bin/i7

	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${CP} -R ${WRKDIR}/Extensions ${STAGEDIR}${DATADIR}

	@${INSTALL_MAN} ${FILESDIR}/i7.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

.if ${ARCH} == "i386"
	@${INSTALL_PROGRAM} ${WRKDIR}/ni.i386 ${STAGEDIR}${PREFIX}/bin/ni
	@${INSTALL_PROGRAM} ${WRKDIR}/inform6.i386 ${STAGEDIR}${PREFIX}/bin/inform6
	@${INSTALL_PROGRAM} ${WRKDIR}/cBlorb.i386 ${STAGEDIR}${PREFIX}/bin/cBlorb
	@${INSTALL_PROGRAM} ${WRKDIR}/dumb-frotz.i386 ${STAGEDIR}${PREFIX}/bin/dumb-frotz
	@${INSTALL_PROGRAM} ${WRKDIR}/dumb-git.i386 ${STAGEDIR}${PREFIX}/bin/dumb-git
	@${INSTALL_PROGRAM} ${WRKDIR}/dumb-glulxe.i386 ${STAGEDIR}${PREFIX}/bin/dumb-glulxe
.else
	@${INSTALL_PROGRAM} ${WRKDIR}/ni.amd64 ${STAGEDIR}${PREFIX}/bin/ni
	@${INSTALL_PROGRAM} ${WRKDIR}/inform6.amd64 ${STAGEDIR}${PREFIX}/bin/inform6
	@${INSTALL_PROGRAM} ${WRKDIR}/cBlorb.amd64 ${STAGEDIR}${PREFIX}/bin/cBlorb
	@${INSTALL_PROGRAM} ${WRKDIR}/dumb-frotz.amd64 ${STAGEDIR}${PREFIX}/bin/dumb-frotz
	@${INSTALL_PROGRAM} ${WRKDIR}/dumb-git.amd64 ${STAGEDIR}${PREFIX}/bin/dumb-git
	@${INSTALL_PROGRAM} ${WRKDIR}/dumb-glulxe.amd64 ${STAGEDIR}${PREFIX}/bin/dumb-glulxe
.endif

.include <bsd.port.post.mk>

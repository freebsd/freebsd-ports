# Created by: Andy Kosela <akosela@andykosela.com>
# $FreeBSD$

PORTNAME=	inform7
PORTVERSION=	6L38
CATEGORIES=	games
MASTER_SITES=	http://ifarchive.org/if-archive/infocom/compilers/inform7/executables/
DISTNAME=	I7_6L38_FreeBSD

MAINTAINER=	akosela@andykosela.com
COMMENT=	Inform 7 programming language (CLI edition)

RUN_DEPENDS=	frotz:games/frotz

ONLY_FOR_ARCHS=	i386 amd64

USES=		zip
SUB_FILES=	i7.sh
NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/i7.sh ${STAGEDIR}${PREFIX}/bin/i7

	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${CP} -R ${WRKSRC}/Internal ${STAGEDIR}${DATADIR}

	${INSTALL_MAN} ${FILESDIR}/i7.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

.if ${ARCH} == "i386"
	${INSTALL_PROGRAM} ${WRKSRC}/ni.i386 ${STAGEDIR}${PREFIX}/bin/ni
	${INSTALL_PROGRAM} ${WRKSRC}/inform6.i386 \
		${STAGEDIR}${PREFIX}/bin/inform6
	${INSTALL_PROGRAM} ${WRKSRC}/cBlorb.i386 \
		${STAGEDIR}${PREFIX}/bin/cBlorb
	${INSTALL_PROGRAM} ${WRKSRC}/dumb-frotz.i386 \
		${STAGEDIR}${PREFIX}/bin/dumb-frotz
	${INSTALL_PROGRAM} ${WRKSRC}/dumb-git.i386 \
		${STAGEDIR}${PREFIX}/bin/dumb-git
	${INSTALL_PROGRAM} ${WRKSRC}/dumb-glulxe.i386 \
		${STAGEDIR}${PREFIX}/bin/dumb-glulxe
.else
	${INSTALL_PROGRAM} ${WRKSRC}/ni.amd64 ${STAGEDIR}${PREFIX}/bin/ni
	${INSTALL_PROGRAM} ${WRKSRC}/inform6.amd64 \
		${STAGEDIR}${PREFIX}/bin/inform6
	${INSTALL_PROGRAM} ${WRKSRC}/cBlorb.amd64 \
		${STAGEDIR}${PREFIX}/bin/cBlorb
	${INSTALL_PROGRAM} ${WRKSRC}/dumb-frotz.amd64 \
		${STAGEDIR}${PREFIX}/bin/dumb-frotz
	${INSTALL_PROGRAM} ${WRKSRC}/dumb-git.amd64 \
		${STAGEDIR}${PREFIX}/bin/dumb-git
	${INSTALL_PROGRAM} ${WRKSRC}/dumb-glulxe.amd64 \
		${STAGEDIR}${PREFIX}/bin/dumb-glulxe
.endif

.include <bsd.port.post.mk>

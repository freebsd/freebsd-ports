# New ports collection makefile for: 	emacs-chess
# Date created:				05 March 2003
# Whom:				 	Steffen Mazanek
#
# $FreeBSD$
#

PORTNAME=		emacs-chess
PORTVERSION=		2.0b5
CATEGORIES=		games elisp
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			http://bsdchat.com/dist/dryice/
MASTER_SITE_SUBDIR=	emacs-chess
DISTFILES=		chess-${PORTVERSION}.tar.bz2 \
			sounds.tar.bz2 \
			pieces.tar.bz2

MAINTAINER=		dryice@liu.com.cn
COMMENT=		Play chess with emacs

EMACS_PORT_NAME=	emacs21
USE_BZIP2=		yes
USE_GMAKE=		yes
WRKSRC=			${WRKDIR}/chess-${PORTVERSION}
LISPDIR=		${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
INFO=			chess

BUILD_DEPENDS+= \
	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/tree-widget/tree-widget.el:${PORTSDIR}/editors/tree-widget
RUN_DEPENDS+=	${BUILD_DEPENDS}

OPTIONS=	ENGINE_GNUCHESS "Gnuchess engine" off
OPTIONS+=	ENGINE_CRAFTY "Crafty chess engine" off
OPTIONS+=	ENGINE_PHALANX "Phalanx chess engine" off

.include <bsd.port.pre.mk>

.if defined(WITH_ENGINE_GNUCHESS)
RUN_DEPENDS+=		gnuchess:${PORTSDIR}/games/gnuchess
.endif

.if defined(WITH_ENGINE_CRAFTY)
RUN_DEPENDS+=		crafty:${PORTSDIR}/games/crafty
.endif

.if defined(WITH_ENGINE_PHALANX)
RUN_DEPENDS+=		phalanx:${PORTSDIR}/games/phalanx
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog chess.ps COPYING EPD.txt PGN.txt PLAN README TODO
.endif

pre-build:
	@(cd ${WRKSRC} && ${RM} -f *.elc *.info)

do-install:
	@(mkdir -p ${LISPDIR}/${PORTNAME} || ${ECHO} "directory exists")
	${CP} ${WRKSRC}/*.elc ${LISPDIR}/${PORTNAME}
	${CP} ${WRKSRC}/*.el ${LISPDIR}/${PORTNAME}
	${CP} ${WRKSRC}/*.info ${PREFIX}/info/
	${CP} -r ${WRKDIR}/sounds ${LISPDIR}/${PORTNAME}
	${CP} -r ${WRKDIR}/pieces ${LISPDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	install-info --dir ${PREFIX}/info/dir ${PREFIX}/info/chess.info
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

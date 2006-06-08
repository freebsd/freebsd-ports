# New ports collection makefile for:	nML
# Date created:		17 July 2001
# Whom:			Jaeho Shin <netj@sparcs.kaist.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	nml
PORTVERSION=	0.92b
CATEGORIES=	lang
MASTER_SITES=	http://ropas.snu.ac.kr/n/ \
		http://sparcs.kaist.ac.kr/~netj/n/ \
		http://ropas.kaist.ac.kr/n/

MAINTAINER=	netj@sparcs.kaist.ac.kr
COMMENT=	A dialect/harmony of Standard ML of New Jersey and Objective Caml

WRKSRC=		${WRKDIR}/${PORTNAME}-0.92

ONLY_FOR_ARCHS=	i386

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
		-prefix ${PREFIX}

USE_GMAKE=	yes
ALL_TARGET=	all opt opt.opt
INSTALL_TARGET=	install installopt

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/LICENSE ${WRKSRC}/README ${DOCSDIR}
	${MKDIR} ${DATADIR}/contrib/emacs
	${MKDIR} ${DATADIR}/contrib/vim
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/* ${DATADIR}/contrib/emacs
	${INSTALL_DATA} ${WRKSRC}/contrib/vim/* ${DATADIR}/contrib/vim
.endif
	@${STRIP_CMD} ${PREFIX}/bin/ncamlrun

.include <bsd.port.post.mk>

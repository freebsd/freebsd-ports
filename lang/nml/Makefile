# New ports collection makefile for:	nML
# Date created:		17 July 2001
# Whom:			Jaeho Shin <netj@ropas.kaist.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	nml
PORTVERSION=	0.92
CATEGORIES=	lang
MASTER_SITES=	http://ropas.kaist.ac.kr/n/

MAINTAINER=	netj@ropas.kaist.ac.kr

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
		-prefix ${PREFIX}

USE_GMAKE=	yes
ALL_TARGET=	all opt opt.opt
INSTALL_TARGET=	install installopt

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changes ${WRKSRC}/LICENSE ${WRKSRC}/README ${DOCSDIR}
	${MKDIR} ${DATADIR}/contrib/emacs
	${MKDIR} ${DATADIR}/contrib/vim
	${INSTALL_DATA} ${WRKSRC}/contrib/emacs/* ${DATADIR}/contrib/emacs
	${INSTALL_DATA} ${WRKSRC}/contrib/vim/* ${DATADIR}/contrib/vim
.endif
	@strip ${PREFIX}/bin/ncamlrun

.include <bsd.port.mk>

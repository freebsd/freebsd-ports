# New ports collection makefile for:	unnethack
# Date created:		19 January 2010
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	unnethack
PORTVERSION=	3.5.3.20101010
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:R}

DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A new variant of NetHack

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES+=	pkg-deinstall
# This port accually conflicts with other nethack variant ports on
# these commands that are only significant for those who want to
# "hack" the game in deep.
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 recover.6 ${PORTNAME}.6
MAKE_JOBS_UNSAFE=	yes

MAKE_ENV+=	DATADIR="${DATADIR}"

post-patch:
	${REINPLACE_CMD} -e \
		"s@%%DATADIR%%@${DATADIR}@g" ${WRKSRC}/include/config.h
	${MV} ${WRKSRC}/doc/nethack.6 ${WRKSRC}/doc/${PORTNAME}.6

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@(cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} manpages)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${LN} -sf ${PREFIX}/share/${PORTNAME}/Guidebook.txt ${DOCSDIR}/
	${INSTALL_DATA} ${FILESDIR}/sample.unnethackrc ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for: Slash'Em (tty interface)
# Date created:	15th April 2001
# Whom:	Adam Kranzel (adam@alameda.edu)
#
# $FreeBSD$
#

PORTNAME=	slashem
PORTVERSION=	0.0.7E.7F.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/0.0.7E7F3
PKGNAMESUFFIX=	-tty
DISTNAME=	se${PORTVERSION:S/.//g:L}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A dungeon explorin', slashin', hackin' game

USE_GMAKE=	yes
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES+=	pkg-deinstall
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 recover.6 slashem.6

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/([A-Z])./\1/g}
MAKE_ENV+=	DATADIR="${DATADIR}"

post-patch:
	${REINPLACE_CMD} -e \
		"s@%%DATADIR%%@${DATADIR}@g" ${WRKSRC}/include/config.h

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@(cd ${WRKSRC}/doc; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} manpages)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/Guidebook.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/slamfaq.txt ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/sample.slashemrc ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

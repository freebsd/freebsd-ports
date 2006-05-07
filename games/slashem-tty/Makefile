# New ports collection makefile for: Slash'Em (tty interface)
# Date created:	15th April 2001
# Whom:	Adam Kranzel (adam@alameda.edu)
#
# $FreeBSD$
#

PORTNAME=	slashem
PORTVERSION=	0.0.6E.4F.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-tty
DISTNAME=	se${PORTVERSION:S/.//g:L}

MAINTAINER=	clive@darkarts.co.za
COMMENT=	A dungeon explorin', slashin', hackin' game

USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 slashem-tty.6 recover.6

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/([A-Z])./\1/g}

post-patch:
	${REINPLACE_CMD} -e \
		"s@/usr/local@${PREFIX}@g" ${WRKSRC}/include/config.h

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@cp ${WRKSRC}/doc/slashem.6 ${WRKSRC}/doc/slashem${PKGNAMESUFFIX}.6
	@cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_MAN} ${WRKSRC}/doc/Guidebook.txt ${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_MAN} ${WRKSRC}/slamfaq.txt ${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_MAN} ${FILESDIR}/sample.slashemrc ${DOCSDIR}${PKGNAMESUFFIX}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

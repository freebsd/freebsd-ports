# New ports collection makefile for: Slash'Em (tty interface)
# Date created:	15th April 2001
# Whom:	Adam Kranzel (adam@alameda.edu)
#
# $FreeBSD$
#

PORTNAME=	slashem
PORTVERSION=	0.0.6E.4F.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-tty
DISTNAME=	se006e4f3

MAINTAINER=	adam@alameda.edu

USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 slashem-tty.6 recover.6

WRKSRC=		${WRKDIR}/slashem-0.0.6E4F3

post-patch:
	${PERL} -pi -e "s@/usr/local@${PREFIX}@g" ${WRKSRC}/include/config.h

pre-configure:
	@cd ${WRKSRC}/sys/unix; ${SH} setup.sh

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@cp ${WRKSRC}/doc/slashem.6 ${WRKSRC}/doc/slashem${PKGNAMESUFFIX}.6
	@cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	${CP} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/share/doc/slashem${PKGNAMESUFFIX}
	${CP} ${WRKSRC}/slamfaq.txt ${PREFIX}/share/doc/slashem${PKGNAMESUFFIX}
	${CP} ${FILESDIR}/sample.slashemrc ${PREFIX}/share/doc/slashem${PKGNAMESUFFIX}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

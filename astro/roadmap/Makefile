# New ports collection makefile for:  roadmap
# Date created:        4 November 2002
# Whom:                Nick Esborn <nick@netdot.net>
#
# $FreeBSD$
#

PORTNAME=	roadmap
PORTVERSION=	0.6
CATEGORIES=	astro
MASTER_SITES=	http://www.geocities.com/pascal_f_martin/roadmap/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_0_6_src
EXTRACT_SUFX=	.tgz

MAINTAINER=	nick@netdot.net

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/src

USE_GNOMENG=	yes
USE_GNOME=	gtk12

BINARIES=	buildmap buildus dumpmap roadmap roadgps
DOCS=		AUTHORS BUGS COPYING README TODO
DOCDIR=		${PREFIX}/share/doc/${PORTNAME}

do-install:
.for bin in ${BINARIES}
	$(INSTALL_PROGRAM) ${BUILD_WRKSRC}/${bin} ${LOCALBASE}/bin
.endfor
	${MKDIR} ${PREFIX}/share/roadmap

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
.for doc in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${DOCDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

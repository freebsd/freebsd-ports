# New ports collection makefile for:	skite
# Date created:				27 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scite
PORTVERSION=	1.42
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.scintilla.org/
MASTER_SITE_SUBDIR=	scintilla
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	scintilla.1:${PORTSDIR}/x11-toolkits/scintilla

WRKSRC=		${WRKDIR}/${PORTNAME}/gtk

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
MAKEFILE=	makefile
MAKE_ENV=	MKDIR="${MKDIR}"

post-extract:
	@${PERL} -pi -e  's|\x0d||' ${WRKSRC}/makefile

.include <bsd.port.mk>

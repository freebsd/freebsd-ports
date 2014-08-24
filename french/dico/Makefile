# Created by: Cyrille Lefevre <clefevre@citeweb.net>
# $FreeBSD$

PORTNAME=	dico
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	french
MASTER_SITES=	ftp://ftp.supelec.fr/lsi/pub/security/
DISTNAME=	le_dico

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive dictionary in french

BROKEN_WWW=	http://www.montefiore.ulg.ac.be/cgi-bin-ulg/DICO.html

# Global variables
#

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_AUTOTOOLS=	automake14 autoconf
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
USES=		gmake
AUTOMAKE_ARGS=	--add-missing --foreign --include-deps
MAKE_ARGS=	prefix=${PREFIX}
REINPLACE_SUB=	PREFIX=${PREFIX}

# Post-patch
#

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/sources/dico.c

# Pre-configure
#

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}

.include <bsd.port.mk>

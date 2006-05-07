# New ports collection makefile for:	dico
# Date created:				11 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	dico
PORTVERSION= 	1.1
PORTREVISION=	4
CATEGORIES=	french
MASTER_SITES=	http://homepages.starnet.fr/dtrystram/
#	http://www.montefiore.ulg.ac.be/~geuzaine/BRONNE/WWW/ftp/ le_dico.tgz
#	ftp://ftp.supelec.fr/lsi/pub/security/			le_dico.tar.gz
#	http://homepages.starnet.fr/dtrystram/			ledico.zip
#	http://hpux.cict.fr/ftp/hpux/Text/     dico-1.1/dico-1.1-ss-11.00.tar.gz
#	ftp://ftp.ac-amiens.fr/pub/Educatifs_fr/Francais	ledico.zip
DISTNAME=	ledico

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive dictionary in french
BROKEN_WWW=	http://www.montefiore.ulg.ac.be/cgi-bin-ulg/DICO.html

# Global variables
#

USE_ZIP=	true
EXTRACT_CMD=	UNZIP= unzip
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_AUTOTOOLS=	automake:14 autoconf:213
USE_GMAKE=	true
AUTOMAKE_ARGS=	--add-missing --foreign --include-deps
MAKE_ARGS=	prefix=${PREFIX}
MAN1=		dico.1
REINPLACE_SUB=	PREFIX=${PREFIX}

# Post-patch
#

post-patch:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/sources/dico.c

# Pre-configure
#

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}

# Post-install
#

post-install:
.if defined(NOPORTDOCS)
	@${RM} -rf ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	dico
# Date created:				11 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	dico
PORTVERSION= 	1.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.montefiore.ulg.ac.be/~geuzaine/BRONNE/WWW/ftp/
#		ftp://ftp.supelec.fr/lsi/pub/security/
#		have dico.tar.gz which fail because of EXTRACT_SUFX
DISTNAME=	le_dico
EXTRACT_SUFX=	.tgz

MAINTAINER=	cyrille.lefevre@laposte.net

NO_WRKSUBDIR=	true
PATCH_STRIP=	-p1
USE_AUTOMAKE=	true
USE_GMAKE=	true
AUTOMAKE_ARGS=	--add-missing --foreign --include-deps
MAKE_ARGS=	prefix=${PREFIX}
MAN1=		dico.1

post-patch:
	@${PERL} -pi.fbsd -e 's.!!PREFIX!!.${PREFIX}.g' ${WRKSRC}/sources/dico.c

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL}

.include <bsd.port.mk>

# Ports collection makefile for:  pnet
# Date created:			  Fri Jul 13 01:08:14 EDT 2001
# Whom:				  Michael Johnson <ahze@rgv.net>
#
# $FreeBSD$
#

PORTNAME=	pnet
PORTVERSION=	0.4.4
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	ahze@rgv.net

BUILD_DEPENDS=	treecc-0.1.8:${PORTSDIR}/lang/treecc

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
STRIP=		#

MAN1=		ilrun.1 ilasm.1 ildasm.1 ilsize.1 ilnative.1 ilfind.1	\
		ildiff.1 ildd.1 cscc.1 csdoc.1	resgen.1 csdoc2texi.1	\
		csdoc2html.1 csdoc2hier.1 clrwrap.1

pre-patch:
	@${REINPLACE_CMD} -e 's|csdoc csant samples doc tests|csdoc csant doc|g' \
		${WRKSRC}/Makefile.*

.include <bsd.port.mk>

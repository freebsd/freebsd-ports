# Ports collection makefile for:  pnet
# Date created:			  Fri Jul 13 01:08:14 EDT 2001
# Whom:				  Michael Johnson <ahze@rgv.net>
#
# $FreeBSD$
#

PORTNAME=	pnet
PORTVERSION=	0.3.0
CATEGORIES=	lang
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	ahze@rgv.net

BUILD_DEPENDS=	treecc:${PORTSDIR}/lang/treecc

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		cscc.1 csdoc.1 csdoc2html.1 csdoc2texi.1 ilasm.1 \
		ildasm.1 ildiff.1 ilfind.1 ilnative.1 ilsize.1 \
		resgen.1

.include <bsd.port.mk>

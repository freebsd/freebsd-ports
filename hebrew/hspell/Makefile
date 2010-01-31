# Ports collection makefile for:  hspell
# Date created:			  03 Feb 2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hspell
PORTVERSION=	1.0
CATEGORIES=	hebrew
MASTER_SITES=	http://www.ivrix.org.il/projects/spell-checker/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	makc

MAINTAINER=	onatan@gmail.com
COMMENT=	Hebrew spellchecker and morphology engine

USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC

MAN1=		hspell.1
MAN3=		hspell.3
SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

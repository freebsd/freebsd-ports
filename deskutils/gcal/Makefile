# New ports collection makefile for:	gcal
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=		gcal
PORTVERSION=		3.01
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcal

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes

# required to rebuild info files if needed.
USE_GMAKE=	yes

# PREFIX isn't honored. force it w/ prefix.
MAKE_ARGS=	prefix="${PREFIX}"

MAN1=		gcal.1 gcal2txt.1 tcal.1 txt2gcal.1

# Local variables
#

INSTALL_INFO?=	install-info

# Post-extract
#

# it's not so simple to get rid of splitted *.info-* files
# w/ hacking doc/Makefile.in. so, do nothing and left them.
# post-extract:
# 	@${RM} -f ${WRKSRC}/doc/*/${PORTNAME}.info*

# Post-install
#

post-install: install-info

install-info:
	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME}.info ${PREFIX}/info/dir

.include <bsd.port.mk>

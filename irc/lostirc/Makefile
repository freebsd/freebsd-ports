# New ports collection makefile for:	irc/lostirc
# Date created:				01 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	lostirc
PORTVERSION=	0.1.4
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rael@vectorstar.net

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
		sigc:${PORTSDIR}/devel/libsigc++

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

MAN1=	lostirc.1

DOCS=	AUTHORS COPYING ChangeLog TODO README INSTALL

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

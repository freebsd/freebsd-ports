# New ports collection makefile for:	irc/lostirc
# Date created:				01 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	lostirc
PORTVERSION=	0.2.5
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rael@vectorstar.net

LIB_DEPENDS=	gtkmm-2.0.2:${PORTSDIR}/x11-toolkits/gtk--2 \
		intl.4:${PORTSDIR}/devel/gettext

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=	lostirc.1

DOCS=	AUTHORS COPYING ChangeLog TODO README INSTALL

post-patch:
	${REINPLACE_CMD} -E "s@^(Gnomedir = ).*@\1${PREFIX}/share/gnome/apps/Internet@" ${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -E "s@(Gnomedir = ).*@\1${PREFIX}/share/gnome/apps/Internet@" ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	ebview
# Date Created:		28 Jan 2002
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ebview
PORTVERSION=	0.1.4
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	eb.6:${PORTSDIR}/japanese/eb

USE_GNOMENG=	yes
USE_GNOME=	imlib
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	SUBDIRS=src
CONFIGURE_ARGS=	--disable-imlibtest

post-install:
	${MKDIR} ${PREFIX}/share/locale/ja/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/ja.gmo ${PREFIX}/share/locale/ja/LC_MESSAGES/ebview.mo
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	pureadmin
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pureadmin
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	purify

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Management utility for the PureFTPd

LIB_DEPENDS=	fam.0:${PORTSDIR}/devel/fam

USE_GNOME=	gnomeprefix gnomehack pkgconfig gtk20
USE_X_PREFIX=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/pureadmin bin/pureadminsearch \
		share/locale/fr/LC_MESSAGES/pureadmin.mo \
		share/locale/it/LC_MESSAGES/pureadmin.mo \
		share/locale/sv/LC_MESSAGES/pureadmin.mo \
		share/gnome/applications/pureadmin.desktop \
		share/gnome/pixmaps/pureadmin.png

post-install:
	@${FIND} ${PREFIX}/share/gnome/pureadmin ! -type d | \
		${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/share/gnome/pureadmin -type d | ${SORT} -r | \
		${SED} 's,${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>

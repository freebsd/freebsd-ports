# New ports collection makefile for:	beaver
# Date created:			11 Apr 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		beaver
PORTVERSION=		0.3.1
PORTREVISION=		8
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SAVANNAH} \
			http://gnu.rtin.bz/ftp/savannah/files/beaver/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A programmer's text editor for GTK+ 2.0

USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:15
USE_GNOME=		gnomehack gnomeprefix gtk20 gtksourceview lthack
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>

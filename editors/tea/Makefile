# New ports collection makefile for:	TEA
# Date created:			13 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		tea
PORTVERSION=		2.0
CATEGORIES=		editors
MASTER_SITES=		http://tea.linux.kiev.ua/
DISTNAME=		${PORTNAME}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A simple GTK+ text editor

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=		yes
USE_BZIP2=		yes
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
USE_GCC=		3.3
USE_GNOME=		gtk20
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/doc/tea|${DOCSDIR}|g' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/tea_funx.c

.include <bsd.port.mk>

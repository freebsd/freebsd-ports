# New ports collection Makefile for:	geany
# Date Created:				15 Jan 06
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	geany
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	MrL0Lz@gmail.com
COMMENT=	A fast and lightweight GTK+ IDE

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	vte
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS}|' ${WRKSRC}/scintilla/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/geany.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>

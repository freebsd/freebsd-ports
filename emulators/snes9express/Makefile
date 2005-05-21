# New ports collection makefile for:	snes9express
# Date created:			15 Mar 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	snes9express
PORTVERSION=	1.42
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tlp@liquidx.org
COMMENT=	GTK interface for snes9x

RUN_DEPENDS=	snes9x:${PORTSDIR}/emulators/snes9x

USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_XLIB=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|lstat$$U.o||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9express ${PREFIX}/bin/snes9express
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/snes.s9xskin ${DATADIR}/snes.s9xskin
	${INSTALL_DATA} ${WRKSRC}/snsp.s9xskin ${DATADIR}/snsp.s9xskin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog COPYING NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

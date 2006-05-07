# New ports collection makefile for:    0verkill
# Date created:         5 May 2001
# Whom:                 Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	0verkill
PORTVERSION=	0.16
CATEGORIES=	games
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mich@FreeBSD.org
COMMENT=	0verkill is a bloody 2D action deathmatch-like game in ASCII-ART

GNU_CONFIGURE=	yes

.if defined(WITHOUT_X11)
PLIST_SUB=	X11="@comment "
.else
USE_XPM=	yes
CONFIGURE_ARGS+=	--with-x
PLIST_SUB=	X11=""
.endif

pre-everything::
.if !defined(WITHOUT_X11)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile without X11 support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITHOUT_X11=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/data/|g' ${WRKSRC}/cfg.h
	@${REINPLACE_CMD} -e 's|grx/|${DATADIR}/grx/|g' ${WRKSRC}/data/*
	@${REINPLACE_CMD} -e 's|-O3 ||g ; \
		 s|gcc |\$$\(CC\) |g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/0verkill ${PREFIX}/bin
.for file in avi bot editor server test_server
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin/0verkill-${file}
.endfor
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/x0verkill ${PREFIX}/bin
.for file in avi editor
	${INSTALL_PROGRAM} ${WRKSRC}/x${file} ${PREFIX}/bin/x0verkill-${file}
.endfor
.endif
	@${MKDIR} ${DATADIR}/data
.for file in banner.dat level.dat sprites.dat *.sp *.dn *.st
	${INSTALL_DATA} ${WRKSRC}/data/${file} ${DATADIR}/data
.endfor
	@${MKDIR} ${DATADIR}/grx
	${INSTALL_DATA} ${WRKSRC}/grx/* ${DATADIR}/grx
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS README.html avi.txt bot.txt doc.html
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

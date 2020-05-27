# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	0verkill
PORTVERSION=	0.16
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~brain/0verkill/release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Bloody 2D action deathmatch-like game in ASCII art

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=X11

OPTIONS_SUB=	yes
X11_USES=	xorg
X11_USE=	XORG=xpm
X11_CONFIGURE_WITH=	x

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/data/|g' ${WRKSRC}/cfg.h
	@${REINPLACE_CMD} -e 's|-O3 ||g ; \
		 s|gcc |\$$\(CC\) |g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/0verkill ${STAGEDIR}${PREFIX}/bin
.for filename in avi bot editor server test_server
	${INSTALL_PROGRAM} ${WRKSRC}/${filename} \
		${STAGEDIR}${PREFIX}/bin/0verkill-${filename}
.endfor
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/x0verkill ${STAGEDIR}${PREFIX}/bin
.for filename in avi editor
	${INSTALL_PROGRAM} ${WRKSRC}/x${filename} \
		${STAGEDIR}${PREFIX}/bin/x0verkill-${filename}
.endfor
.endif
.for dir in data grx
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${DATADIR}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for filename in AUTHORS README.html avi.txt bot.txt doc.html
	${INSTALL_DATA} ${WRKSRC}/doc/${filename} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

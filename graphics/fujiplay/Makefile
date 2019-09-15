# Created by: KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	fujiplay
PORTVERSION=	1.33
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://topo.math.u-psud.fr/~bousch/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital camera downloading tool for Fujifilm digital cameras

BROKEN=		unfetchable
DEPRECATED=	Unfetchable, unmaintained
EXPIRATION_DATE=	2019-10-16

NO_WRKSUBDIR=	yes

USES=		tar:tgz
PLIST_FILES=	bin/fujiplay bin/yycc2ppm
PORTDOCS=	README fujiplay.lsm mx700-commands.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC[^g]*\)gcc$$|\1${CC}|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC}; ${INSTALL_PROGRAM} fujiplay yycc2ppm ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/fujiplay
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/share/doc/fujiplay
.endfor

.include <bsd.port.mk>

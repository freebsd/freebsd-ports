# New ports collection makefile for:	libjconv
# Date created:		12 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libjconv
PORTVERSION=	2.9
CATEGORIES=	japanese
MASTER_SITES=	http://ghost.math.sci.hokudai.ac.jp/misc/libjconv/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese charset conversion library powered by iconv(3)

#RUN_DEPENDS=	${LOCALBASE}/libexec/iconv/iso-2022-jp.so:${PORTSDIR}/converters/iconv-extra

MAKE_ARGS=	NOPROFILE=true PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}
INSTALLS_SHLIB=	yes
USE_ICONV=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,!!PREFIX!!,${PREFIX},' ${WRKSRC}/info.c

post-extract:
	${CP} ${FILESDIR}/Makefile* ${WRKSRC}/

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/libjconv.html ${DOCSDIR}/

.include <bsd.port.mk>

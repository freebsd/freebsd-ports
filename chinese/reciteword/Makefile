# Created by: hamigua <hamigua@cuc.cn>
# $FreeBSD$

PORTNAME=	reciteword
PORTVERSION=	0.8.5
CATEGORIES=	chinese
MASTER_SITES=	SF:src \
		SF/${PORTNAME}/${PORTNAME}-books/${PORTVERSION}:books \
		SF/${PORTNAME}/${PORTNAME}-dicts/0.8.2:dicts
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2:src \
		${PORTNAME}-books-${PORTVERSION}.tar.bz2:books \
		${PORTNAME}-dicts-0.8.2.tar.bz2:dicts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Education software to help people to study English

LIB_DEPENDS=	libespeak.so:${PORTSDIR}/audio/espeak

GNU_CONFIGURE=	yes
USES=		tar:bzip2 gettext gmake pkgconfig
USE_GNOME=	gtk20 esound
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO readme.txt

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' ${WRKSRC}/src/readword.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} "books dicts" ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

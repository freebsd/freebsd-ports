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

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 esound
CPPFLAGS+=	"-I${LOCALBASE}/include"

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO readme.txt

XTRACT_AFTER_ARGS+=	--exclude CVS

NO_STAGE=	yes
.include <bsd.port.options.mk>

LIB_DEPENDS+=	libespeak.so:${PORTSDIR}/audio/espeak

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' ${WRKSRC}/src/readword.cpp

post-install:
	@${MKDIR} ${DATADIR}
	(cd ${WRKDIR}/ && ${COPYTREE_SHARE} "books dicts" ${DATADIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

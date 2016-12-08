# Created by: hamigua <hamigua@cuc.cn>
# $FreeBSD$

PORTNAME=	reciteword
PORTVERSION=	0.8.5
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	SF \
		SF/${PORTNAME}/${PORTNAME}-books/${PORTVERSION}:books \
		SF/${PORTNAME}/${PORTNAME}-dicts/0.8.2:dicts
DISTFILES=	${DISTNAME}.tar.bz2 \
		${PORTNAME}-books-${PORTVERSION}.tar.bz2:books \
		${PORTNAME}-dicts-0.8.2.tar.bz2:dicts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Education software to help people to study English

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libespeak.so:audio/espeak

GNU_CONFIGURE=	yes
USES=		tar:bzip2 gettext gmake pkgconfig
USE_GNOME=	gtk20 intltool esound
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS ChangeLog INSTALL README readme.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' ${WRKSRC}/src/readword.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} "books dicts" ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

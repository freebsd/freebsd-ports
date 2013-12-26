# Created by: David K. Gerry
# $FreeBSD$

PORTNAME=	yasr
PORTVERSION=	0.6.9
PORTREVISION=	2
CATEGORIES=	accessibility
MASTER_SITES=	SF

MAINTAINER=	David.K.Gerry@GMail.com
COMMENT=	General-purpose console screen reader

LICENSE=	LGPL20

USES=		gmake
GNU_CONFIGURE=	yes
PORTDOCS=	AUTHORS BUGS CREDITS ChangeLog NEWS README TODO \
		README-br README-de README-es README-fr README-ru
SUB_FILES=	pkg-message

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

PLIST_FILES=	bin/yasr \
		%%DATADIR%%/yasr.conf \
		%%NLS%%share/locale/es/LC_MESSAGES/yasr.mo \
		%%NLS%%share/locale/fr/LC_MESSAGES/yasr.mo
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
EXTRA_PATCHES=	${FILESDIR}/extra-patch-yasr__main.c
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/csh|' ${WRKSRC}/yasr.conf

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>

# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	esecanna
PORTVERSION=	1.0.1
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	esecanna

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pseudo cannaserver which wraps some other input engines

USE_RC_SUBR=	esecanna

GNU_CONFIGURE=	yes
USES=		gmake
CONFIGURE_ARGS=	--with-piddir="/var/run/esecanna"

DOCS=		CREDITS CHANGES.jp README.First.jp README.jp

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e " \
		s,!!PREFIX!!,${PREFIX},g; \
		" \
		${WRKSRC}/README.jp \
		${WRKSRC}/esecannarc

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/esecanna
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/esecanna
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

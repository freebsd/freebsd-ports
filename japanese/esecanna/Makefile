# New ports collection Makefile for: esecanna
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	esecanna
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	knu
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	esecanna

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Pseudo cannaserver which wraps some other input engines

USE_REINPLACE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-piddir="${PIDDIR}"

PIDDIR=		/var/run/esecanna
STARTER=	esecanna.sh
DOCS=		CREDITS CHANGES.jp README.First.jp README.jp

PLIST_SUB=	STARTER="${STARTER}"

post-extract:
	${SED} -e " \
		s,!!PREFIX!!,${PREFIX},g; \
		s,!!STARTER!!,${STARTER},g; \
		" \
		${FILESDIR}/esecanna.sh > ${WRKSRC}/${STARTER}

post-patch:
	${REINPLACE_CMD} -e " \
		s,!!PREFIX!!,${PREFIX},g; \
		" \
		${WRKSRC}/README.jp \
		${WRKSRC}/esecannarc

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${STARTER} ${PREFIX}/etc/rc.d/
	${MKDIR} ${PREFIX}/lib/esecanna
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/esecanna/
.endif
	${MKDIR} ${PIDDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection Makefile for: esecanna
# Version required:	0.14.2
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	esecanna_0.14.2
PKGNAME=	ja-esecanna-0.14.2
CATEGORIES=	japanese
MASTER_SITES=	http://esecanna.netfort.gr.jp/ \
		http://people.FreeBSD.org/~knu/ports/distfiles/

MAINTAINER=	knu@idaemons.org

USE_AUTOCONF=	yes
USE_GMAKE=	yes

DIST_SUBDIR=	esecanna

STARTER=	esecanna.sh
DOCS=		CHANGES.jp README.First.jp README.jp

PLIST_SUB=	STARTER="${STARTER}"

post-extract:
	${PERL} -pe " \
		s,!!PREFIX!!,${PREFIX},g; \
		s,!!STARTER!!,${STARTER},g; \
		" \
		${FILESDIR}/esecanna.sh > ${WRKSRC}/${STARTER}

post-patch:
	cd ${WRKSRC} && ${PERL} -i -pe " \
		s,!!PREFIX!!,${PREFIX},g; \
		" \
		README.jp \
		esecannarc

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${STARTER} ${PREFIX}/etc/rc.d/
	${MKDIR} ${PREFIX}/lib/esecanna
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${PREFIX}/share/doc/esecanna/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

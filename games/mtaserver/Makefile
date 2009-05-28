# New ports collection makefile for:	mtaserver
# Date created:				25 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	${MTANAME:L}
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://files.gonnaplay.com/201/:main \
		http://www.trancevibez.com/mta/:both \
		http://files.gonnaplay.com/20104/:patch
DISTFILES=	${MTANAME}0_5-linux.tar.gz:main,both ${MTANAME}0_5-linux-patch1.tar.gz:patch,both
DIST_SUBDIR=	mta

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Multi Theft Auto: Vice City and GTA3 dedicated server

USE_LINUX=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_RC_SUBR=	mtad
MTANAME=	MTAServer
MTADIR=		${PREFIX}/lib/${PORTNAME}
PORTDOCS=	CHANGELOG LICENSE README
PLIST_SUB=	MTADIR=${MTADIR:S,^${PREFIX}/,,} MTADIRE=${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	MTADIR=${MTADIR} MTADIRE=${PORTNAME}
.if !defined(NOPORTDOCS)
SUB_LIST+=	NOTEWORK="Read ${DOCSDIR}/README for details"
.else
SUB_LIST+=	NOTEWORK=""
.endif

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKSRC}/${MTANAME} ${WRKSRC}/${PORTNAME}
	@${CHMOD} 600 ${WRKSRC}/${PORTNAME}.conf

post-patch:
	@${REINPLACE_CMD} "s|banned.lst|${PREFIX}/etc/${PORTNAME}/banned.lst|" ${WRKSRC}/${PORTNAME}.conf

do-install:
	${MKDIR} ${MTADIR}
	${BRANDELF} -t Linux ${WRKSRC}/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${MTADIR}
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.if !exists(${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf)
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}
.endif
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf.dist
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
